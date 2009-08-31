-module(eri).

% API
-export([start/0, start/1, stop/0,init/1]).
-export([setup/0, parse/1, eval/1, sum/2]).


start()->
    start("./ERI").
start(ExtPrg) ->
    spawn_link(?MODULE, init, [ExtPrg]).

stop() ->
    ?MODULE ! stop.

setup() -> 
    case call_port({setup}) of
	0->{ok}
    end.

parse(X)->
    call_port({parse,X}).

    
eval(X)->
    io:format("Calling port with eval()~n"),
    parse(X).


init(ExtPrg)->
    register(?MODULE, self()),
    process_flag(trap_exit, true),
    Port = open_port({spawn, ExtPrg}, [{packet,2}, binary]),
    loop(Port).

sum(X,Y) -> call_port({sum, X, Y}).

call_port(Msg) ->
    ?MODULE ! {call, self(), Msg},
    receive
	{?MODULE, Result}->
	    Result
    end.

loop(Port) ->
    receive
	{call, Caller, Msg} ->
	    Port ! {self(), {command, term_to_binary(Msg)}},
	    receive
		{Port, {data, Data}} ->
		    Caller ! {eri, binary_to_term(Data)}
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
