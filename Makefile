CC=gcc
CFLAGS=
LDFLAGES=
LDLIBS=
SRC = src

ifeq (DEBUG, 1)
	CLFAGS += -g
endif

parser:$(SRC)/main.o $(SRC)/dex_parser_header.o
		$(CC) -o $@ $(SRC)/main.o $(SRC)/dex_parser_header.o



$(TARGET):$(OBJS)
		$(CC) -c -o $@ $(OBJS)

$(SRC)/dex_parser_header.o : $(SRC)/dex_parser_header.c
$(SRC)/main.o : $(SRC)/main.c



clean:
		rm -f parser $(SRC)/*.o
