-module(rErlang).

% API
-export([test/1, eval/1]).

test(X)->
   X*2.

eval(Buf)->
    Buf.

