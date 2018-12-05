CC=gcc
CFLAGS= -g -Wall -Wextra
LDFLAGS= -lm
EXEC=ocr
SRC= main.c test.c 
OBJ= $(SRC:.c=.o)

all: $(EXEC)

ocr: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: $(SRC)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -fr *.d
	rm -rf *.o


mrproper: clean
	rm -rf $(EXEC)