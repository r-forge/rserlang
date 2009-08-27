-module(eri).
-export([start/0, stop/0]).
-export([r_eval/1, sum/2]).

start() ->
    spawn(fun() ->
		  register(eri,self()),
		  process_flag(trap_exit, true),
		  Port = open_port({spawn, "./ERI"},[{packet,2}]),
		  loop(Port)
	  end).
stop() ->
    eri ! stop.

r_eval(X) -> call_port({r_eval,X}).
sum(X,Y) -> call_port({sum,X,Y}).

call_port(Msg) ->
    eri ! {call, self(),Msg},
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
