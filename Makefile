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

main = hadamard.o matrice.o

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

coureur : $(main)
	$(GCCLNK) $(main) $(opt) -o main -I ./

hadamard.o : hadamard.c 
	$(GCCOBJ) $(opt) hadamard.c -o hadamard.o -I ./

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

all :   coureur 

#
#-------- All tests -------
#

#
#-------- Tags -------
#

tags :
	etags *.c 