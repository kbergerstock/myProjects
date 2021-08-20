CFLAGS1 = -O2  -flto
CFLAGS2 = -O2   -flto
INC = ../headers
SRC = ../src
CC1 = gcc
CC2 = clang

SRCFILES = $(SRC)/primeSieve.c  $(SRC)/sieve.c  $(SRC)/tbitarray.c

OUTFILE1 = GCCprimeSieve
OUTFILE2 = CLANGprimeSieve

all: $(OUTFILE1) $(OUTFILE2)

$(OUTFILE1):
	$(CC1) --version
	$(CC1) $(CFLAGS1) -I$(INC) $(SRCFILES) -o$(OUTFILE1)

$(OUTFILE2):
	$(CC2) --version
	$(CC2) $(CFLAGS2) -I$(INC) $(SRCFILES) -o$(OUTFILE2)


clean:
	rm $(OUTFILE2)
	rm $(OUTFILE1)
