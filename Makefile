CC=gcc
CFLAGS= -g -Wall -Wextra
LDFLAGS= -lm
EXEC=ocr
SRC= Files/Utility.c Files/Traitement.c Files/Binary.c Files/Segmentation.c main.c
OBJ= $(SRC:.c=.o)

all: $(EXEC)

ocr: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: $(SRC)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -fr Files/*.o
	rm -rf *.o
	rm -rf *.o



mrproper: clean
	rm -rf $(EXEC)
