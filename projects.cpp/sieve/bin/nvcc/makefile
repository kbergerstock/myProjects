CFLAGS = -O2 -D CLOCK_CHRONO -m64
INC = ..\..\headers
SRC = ..\..\src
CC = nvcc.exe

SRCFILES = $(SRC)\primeSieve.cpp  $(SRC)\sieve.cpp  $(SRC)\tbitarray.cpp

OUTFILE = primeSieve.exe

$(OUTFILE):
	$(CC) $(CFLAGS) -I$(INC) $(SRCFILES) -o $(OUTFILE)

clean:
	del primeSieve.exe
