.SUFFIXES: .erl .beam .yrl

.erl.beam:
	erlc -W $<

CC := gcc
RM := rm
MODS = eri

all:	${MODS:%=%.beam} eri

eri:		rengine.c erl_comm.c driver.c
		${CC} -I/usr/share/R/include -o rengine rengine.c erl_comm.c driver.c
clean: 		
		${RM} -rf rengine *.beam *~
