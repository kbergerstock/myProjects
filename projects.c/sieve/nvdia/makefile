CFLAGS = -O2  -D PERFORMANCE_CLOCK  --lto --m64
INC = ..\headers
SRC = ..\src
CC = nvcc

SRCFILES = $(SRC)\primeSieve.c  $(SRC)\sieve.c  $(SRC)\tbitarray.c

OUTFILE = NVCCprimeSieve.exe

$(OUTFILE):
	$(CC) $(CFLAGS) -I$(INC) $(SRCFILES) -o $(OUTFILE)

clean:
	del NVCCprimeSieve.exe
