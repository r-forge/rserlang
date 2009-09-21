.SUFFIXES: .erl .beam .yrl

BINDIR :=../bin

.erl.beam:
	erlc -W -o${BINDIR} eri.erl rErlang.erl

CSRC=$(shell ls *.c)
HED=$(shell ls *.h)
CC := gcc
RM := rm
MODS = eri
PRODUCT_ERI := ERI-0.1
PRODUCT_RE := rErlang-0.1
NODE_SHELL := erl_node.sh
R_FILE := rErlang.R
R_HEADER := /usr/share/R/include
R_LIB := /usr/lib/R/lib
CFLAGS := -Wall -I${R_HEADER} -I${ERL_LIB}/include
LFLAGS := -L${R_LIB} -L${ERL_LIB}/lib -lR -lerl_interface_st -lei_st -lerl_interface -lei

all:	${MODS:%=%.beam} eri

eri:	${HED} ${CSRC}
	${CC} ${CFLAGS} -o ${BINDIR}/${PRODUCT_ERI} ${HED} ${CSRC} ${LFLAGS}
	${CC} -std=gnu99 ${CFLAGS} -fpic  -g -O2 -c rErlang.c -o ${BINDIR}/${PRODUCT_RE}.o
	${CC} -std=gnu99 -shared  -o ${BINDIR}/${PRODUCT_RE}.so ${BINDIR}/${PRODUCT_RE}.o ${LFLAGS}
	cp ${NODE_SHELL} ${R_FILE} ${BINDIR}

clean:
	${RM} -rf ${BINDIR}/${R_FILE} ${BINDIR}/${PRODUCT_ERI} ${BINDIR}/${PRODUCT_RE} ${BINDIR}/*.beam ${BINDIR}/*.sh ${BINDIR}/*.o ${BINDIR}/*.so *~ *# *.o *.so
