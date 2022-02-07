CC=cc
CFLAGS=-std=c99 -Wall -Wextra -Werror -g -O3 -pipe
BIN=qls
OBJS=qls.o main.o

default: all clean
all: $(BIN)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $^

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

install:
	cp $(BIN) /usr/bin

uninstall:
	rm /usr/bin/$(BIN)

clean:
	rm -rf *.o *.gch .*~ *~

run:
	./$(BIN)
