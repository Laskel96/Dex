CC=gcc
CFLAGS=
LDFLAGES=
LDLIBS=
SRC = src

ifeq (DEBUG, 1)
	CLFAGS += -g
endif

parser:$(SRC)/main.o $(SRC)/print_test.o $(SRC)/parse.o
		$(CC) -o $@ $(SRC)/main.o $(SRC)/print_test.o $(SRC)/parse.o



$(TARGET):$(OBJS)
		$(CC) -c -o $@ $(OBJS)

$(SRC)/parse.o : $(SRC)/parse.c
$(SRC)/print_test.o : $(SRC)/print_test.c
$(SRC)/main.o : $(SRC)/main.c



clean:
		rm -f parser $(SRC)/*.o
