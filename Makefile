# MAKEFILE pour Cours sur les files de messages
#
#

#
# Directories
#
top_dir = .


#
# Object files
#

main = hadamard.o matrice.o encodage.o

#
# Options for compilation
#

GCCOBJ = gcc -c
GCCLNK = gcc


# Option for debugger
opt = -g -Wall -D_DEBUG_
# opt = -O2 -Wall
#
#
#

#
#-------- Mains ---------------
#

hadamard : $(main)
	$(GCCLNK) $(main) $(opt) -o main -I ./

hadamard.o : hadamard.c
	$(GCCOBJ) $(opt) -g hadamard.c -o hadamard.o -I ./

encodage.o : encodage.c
	$(GCCOBJ) $(opt) -g encodage.c -o encodage.o -I ./
#
# --- Tests ---
#

#
#-------- Modules -------------
#


matrice.o : matrice.c matrice.h
	$(GCCOBJ) $(opt) matrice.c -o matrice.o -I ./

#
#-------- Headers -------------
#

#
#-------- Clean objects -------
#

clean :
	rm -f *.o

#
#-------- All executables -------
#

all :   hadamard

#
#-------- All tests -------
#

#
#-------- Tags -------
#

tags :
	etags *.c
