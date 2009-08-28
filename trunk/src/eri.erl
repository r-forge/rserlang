-module(eri).

% API
-export([start/0, start/1, stop/0,init/1]).
-export([setup/0,eval/1,r_eval/1, sum/2]).


start()->
    start("./ERI").
start(ExtPrg) ->
    spawn_link(?MODULE, init, [ExtPrg]).

stop() ->
    ?MODULE ! stop.

setup()->
    io:format("Calling port with eri_setup()~n").
    
eval(X)->
    io:format("Calling port with eri_parse(~p)~n",X),
    io:format("Calling port with eri_eval()~n").

init(ExtPrg)->
    register(?MODULE, self()),
    process_flag(trap_exit, true),
    Port = open_port({spawn, ExtPrg}, [{packet,2}]),
    loop(Port).

r_eval(X) -> call_port({r_eval, X}).

sum(X,Y) -> call_port({sum, X, Y}).

call_port(Msg) ->
    ?MODULE ! {call, self(), Msg},
    receive
	{example1, Result}->
	    Result
    end.

loop(Port) ->
    receive
	{call, Caller, Msg} ->
	    Port ! {self(), {command, encode(Msg)}},
	    receive
		{Port, {data, Data}} ->
		    Caller ! {eri, decode(Data)}
	    end,
	    loop(Port);
	stop ->
	    Port ! {self(), close},
	    receive
		{Port, closed} ->
		    exit(normal)
	    end;
	{'EXIT', Port, Reason} ->
	    exit({port_terminated, Reason})
    end.

encode({r_eval, X}) -> [1,X];
encode({sum, X, Y}) -> [2, X, Y].

decode([Int]) -> Int.
