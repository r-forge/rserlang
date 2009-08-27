.SUFFIXES: .erl .beam .yrl

.erl.beam:
	erlc -W $<

CSRC=$(shell ls *.c)
HED=$(shell ls *.h)
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

eri:		${HED} ${CSRC}
		${CC} ${CFLAGS} ${LFLAGS} -o ${PRODUCT} ${HED} ${CSRC}

clean: 		
		${RM} -rf ${PRODUCT} *.beam *~
