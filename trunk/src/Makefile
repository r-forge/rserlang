.SUFFIXES: .erl .beam .yrl

BINDIR :=../bin

.erl.beam:
	erlc -W -o${BINDIR} $<

CSRC=$(shell ls *.c)
HED=$(shell ls *.h)
CC := gcc
RM := rm
MODS = eri
PRODUCT := rErlang-0.1
R_HEADER := /usr/share/R/include
R_LIB := /usr/lib/R/lib
CFLAGS := -Wall -I${R_HEADER} -I${ERL_LIB}/include
LFLAGS := -L${R_LIB} -L${ERL_LIB}/lib -lR -lerl_interface_st -lei_st -lerl_interface -lei

all:	${MODS:%=%.beam} eri

eri:	${HED} ${CSRC}
	${CC} ${CFLAGS}  -o ${BINDIR}/${PRODUCT} ${HED} ${CSRC} ${LFLAGS}

clean:
	${RM} -rf ${BINDIR}/${PRODUCT} ${BINDIR}/*.beam *~
