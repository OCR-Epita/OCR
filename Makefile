CC=gcc
CFLAGS= -g -Wall
PKGCONFIG = $(shell which pkg-config)
LDFLAGS= -lm
LIBS = `pkg-config --cflags --libs gtk+-3.0`
EXEC= ocr
SRC= Files/Utility.c Files/Traitement.c Files/Binary.c main.c Files/Segmentation.c interface/interface.c
OBJ= $(SRC:.c=.o)

all: $(EXEC)


ocr: $(OBJ)
	$(CC) -o  $@ $^ $(LIBS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c  $(LDFLAGS) $< $(LIBS)


main.o: $(SRC)

.PHONY: clean mrproper

clean:
	rm -fr Files/*.o
	rm -rf *.o
	rm -rf *.o



mrproper: clean
	rm -rf $(EXEC)



