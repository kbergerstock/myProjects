CFLAGS = -O2  -m64 -D PERFORMANCE_CLOCK
INC = ..\headers
SRC = ..\src
CC = clang.exe

SRCFILES = $(SRC)\primeSieve.c  $(SRC)\sieve.c  $(SRC)\tbitarray.c

OUTFILE = primeSieve.exe

$(OUTFILE):
	$(CC) $(CFLAGS) -I$(INC) $(SRCFILES) -o$(OUTFILE)

clean:
	del primeSieve.exe
