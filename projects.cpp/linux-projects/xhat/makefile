CFLAGS = -O2 -Ofast -m64
INC = headers
SRC = src
CC = g++

SRCFILES = $(SRC)/main.cpp  $(SRC)/cxLIB.cpp  $(SRC)/cxWIN.cpp $(SRC)/xCANVAS.cpp $(SRC)/Hat.cpp
OUTFILE = bin/xhat

$(OUTFILE):
	$(CC) --version
	$(CC) $(CFLAGS) -I$(INC) $(SRCFILES) -o$(OUTFILE)

clean:
	rm bin/xhat
