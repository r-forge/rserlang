.SUFFIXES: .erl .beam .yrl

.erl.beam:
	erlc -W $<

CC := gcc
RM := rm
MODS = eri
PRODUCT := ERI

all:	${MODS:%=%.beam} eri

eri:		eri.h Rcallbacks.h Rcallbacks.c Rinit.h Rinit.c Rengine.c erl_comm.c driver.c 
		${CC} -I/usr/share/R/include -I/usr/lib/erlang/lib/erl_interface-3.2.1/include  -L/usr/lib/R/lib -L/usr/lib/erlang/lib/erl_interface-3.2.1/lib -lR -lerl_interface -lei -o ERI eri.h Rcallbacks.h Rcallbacks.c Rinit.c Rinit.h  Rengine.c erl_comm.c driver.c 

clean: 		
		${RM} -rf ERI *.beam *~
