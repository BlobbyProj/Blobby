IDIR = include
SDIR = src
ODIR = obj
	
CC = g++
CFLAGS = -I$(IDIR)
LFLAGS = -static-libgcc -static-libstdc++
LIBS = -lmingw32 -lSDLmain -lSDL

_OBJ = main.o screen.o objectmanager.o bug.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

main: $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)

$(ODIR)/main.o: $(SDIR)/main.cxx $(IDIR)/main.h $(IDIR)/screen.h $(IDIR)/objectmanager.h $(IDIR)/bug.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/screen.o: $(SDIR)/screen.cxx $(IDIR)/main.h $(IDIR)/screen.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/objectmanager.o: $(SDIR)/objectmanager.cxx $(IDIR)/main.h $(IDIR)/screen.h $(IDIR)/objectmanager.h $(IDIR)/object.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/bug.o: $(SDIR)/bug.cxx $(IDIR)/main.h $(IDIR)/screen.h $(IDIR)/object.h $(IDIR)/bug.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o