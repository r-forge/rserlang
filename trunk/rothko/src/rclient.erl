-module(rclient).
-behaviour(gen_fsm).

-export([start/1]).
-export([regist/1, reset/1, ping/2,pause/2]).
-export([init/1, terminate/3]).

start(Name) ->
    gen_fsm:start_link({local, Name}, rclient, 0, []).

regist(Name) ->
    couchbeam:start(),
    couchbeam_server:start_connection(),
    couchbeam_server:open_db(default, {somedb,"somedb"}),
    couchbeam_db:info(somedb),    
    gen_fsm:send_event(Name, {ping, 1}).

reset(Name) ->
    gen_fsm:send_event(Name, {reset, 0}).


init(Num) ->
    {ok, ping, Num}.

ping(Event, Data) -> 
	io:format("ping~n"),
	case Event of
    	 {ping, Num} -> NewData = Data + Num;
    	 {reset, Num} -> NewData = Num;
	 timeout -> NewData = 0
    end,
    io:format("vaulue=~p~n", [NewData]),
    {next_state, pause, NewData,3000}.

pause(Event, Data) -> 
	io:format("pause~n"),
	case Event of
    	 {pause, Num} -> NewData = Data + Num;
    	 {reset, Num} -> NewData = Num;
	 timeout -> NewData = 0
    end,
    io:format("vaulue=~p~n", [NewData]),
    {next_state, ping, NewData,3000}.


terminate(_WhatsThis, _StateName, _StateData) ->
    ok.

