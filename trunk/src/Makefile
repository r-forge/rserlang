.SUFFIXES: .erl .beam .yrl

.erl.beam:
	erlc -W $<

CC := gcc
RM := rm
MODS = eri
PRODUCT := ERI
ERL_LIB := /usr/lib/erlang/lib/erl_interface-3.2.1
R_HEADER := /usr/share/R/include 
R_LIB := /usr/lib/R/lib
CFLAGS := -Wall -I${R_HEADER} -I${ERL_LIB}/include
LFLAGS := -L${R_LIB} -L${ERL_LIB}/lib -lR -lerl_interface -lei

all:	${MODS:%=%.beam} eri

eri:		eri.h eri.c Rcallbacks.h Rcallbacks.c Rinit.h Rinit.c Rengine.c erl_comm.c driver.c 
		${CC} ${CFLAGS} ${LFLAGS} -o ERI eri.h eri.c Rcallbacks.h Rcallbacks.c Rinit.c Rinit.h  Rengine.c erl_comm.c driver.c 

clean: 		
		${RM} -rf ERI *.beam *~
