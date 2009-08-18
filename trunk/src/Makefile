.SUFFIXES: .erl .beam .yrl

.erl.beam:
	erlc -W $<
#-L/usr/lib/R/lib -lR
CC := gcc
RM := rm
MODS = eri
PRODUCT := ERI

all:	${MODS:%=%.beam} eri

eri:		eri.h Rcallbacks.h Rcallbacks.c Rinit.h Rinit.c Rengine.c erl_comm.c driver.c /usr/lib/R/lib/libR.so
		${CC} -I/usr/share/R/include -L/usr/lib/R/lib -lR -o ERI eri.h Rcallbacks.h Rcallbacks.c Rinit.c Rinit.h  Rengine.c erl_comm.c driver.c 

clean: 		
		${RM} -rf ERI *.beam *~
