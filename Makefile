CC=gcc
CFLAGS=
LDFLAGES=
LDLIBS=
SRC = src

ifeq (DEBUG, 1)
	CLFAGS += -g
endif

parser:$(SRC)/main.o $(SRC)/parseHeader.o $(SRC)/parseMap.o
		$(CC) -o $@ $(SRC)/main.o $(SRC)/parseHeader.o $(SRC)/parseMap.o

$(TARGET):$(OBJS)
		$(CC) -c -o $@ $(OBJS)

$(SRC)/main.o : $(SRC)/main.c
$(SRC)/parseHeader.o : $(SRC)/parseHeader.c
$(SRC)/parseMap.o : $(SRC)/parseMap.c

clean:
		rm -f parser $(SRC)/*.o
