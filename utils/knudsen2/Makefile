# $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/utils/knudsen2/Makefile,v 1.1.14.1 2003/03/07 05:23:29 heimbach Exp $

     FC = f77
F77OPTS = -r8

all: knudsen2 unesco

knudsen2: knudsen2.o
	$(FC) -o knudsen2 knudsen2.o
unesco: unesco.o
	$(FC) -o unesco unesco.o

.f.o:
	$(FC) $(F77OPTS) -c $<

clean:
	-\rm -f knudsen2 unesco *.o
