CFLAGS = -O2 -Ofast -m64
INC = ../../headers
SRC = ../../src
CC = clang++

SRCFILES = $(SRC)/primeSieve.cpp  $(SRC)/sieve.cpp  $(SRC)/tbitarray.cpp
OUTFILE = primeSieve

$(OUTFILE):
	$(CC) --version
	$(CC) $(CFLAGS) -I$(INC) $(SRCFILES) -o$(OUTFILE)

clean:
	rm primeSieve
