.SUFFIXES: .erl .beam .yrl

BINDIR :=../bin

.erl.beam:
	erlc -W -o${BINDIR} $<

CSRC=$(shell ls *.c)
HED=$(shell ls *.h)
CC := gcc
RM := rm
MODS = eri
PRODUCT := ERI
EI_LIB := erl_interface-3.5.9
ERL_LIB := /usr/lib/erlang/lib/${EI_LIB}
R_HEADER := /usr/share/R/include
R_LIB := /usr/lib/R/lib
CFLAGS := -Wall -I${R_HEADER} -I${ERL_LIB}/include
LFLAGS := -L${R_LIB} -L${ERL_LIB}/lib -lR -lerl_interface_st -lei_st -lerl_interface -lei

all:	${MODS:%=%.beam} eri

eri:	${HED} ${CSRC}
	${CC} ${CFLAGS}  -o ${BINDIR}/${PRODUCT} ${HED} ${CSRC} ${LFLAGS}

clean:
	${RM} -rf ${BINDIR}/${PRODUCT} ${BINDIR}/*.beam *~
