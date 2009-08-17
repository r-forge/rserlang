.SUFFIXES: .erl .beam .yrl

.erl.beam:
	erlc -W $<

CC := gcc
RM := rm
MODS = eri
PRODUCT := ERI

all:	${MODS:%=%.beam} eri

eri:		Rcallbacks.h Rcallbacks.c Rinit.h Rinit.c Rengine.c erl_comm.c driver.c /usr/lib/R/lib/libR.so
		${CC} -I/usr/share/R/include -o ERI Rcallbacks.h Rcallbacks.c Rinit.c Rinit.h  Rengine.c erl_comm.c driver.c /usr/lib/R/lib/libR.so

clean: 		
		${RM} -rf ERI *.beam *~
