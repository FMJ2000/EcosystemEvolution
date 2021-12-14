IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR)

ODIR = obj
LDIR = ../lib

LIBS = -lm -lsfml-graphics -lsfml-window -lsfml-system

_DEPS = main.hpp const.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~