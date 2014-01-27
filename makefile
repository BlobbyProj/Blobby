IDIR = include
SDIR = src
ODIR = obj
	
CC = g++
CFLAGS = -I$(IDIR)  -std=c++0x
LFLAGS = -static-libgcc -static-libstdc++
LIBS = -lmingw32 -lSDLmain -lSDL

_OBJ = main.o globals.o screen.o objectmanager.o bug.o button.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_DEP = sed -n '/include "/p' test.txt | sed 's/.*"\(.*\)".*/\1/'

main: $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)

$(ODIR)/main.o: $(SDIR)/main.cxx $(IDIR)/globals.h $(IDIR)/screen.h $(IDIR)/objectmanager.h $(IDIR)/bug.h $(IDIR)/button.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/globals.o: $(SDIR)/globals.cxx $(IDIR)/globals.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/screen.o: $(SDIR)/screen.cxx $(IDIR)/globals.h $(IDIR)/screen.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/objectmanager.o: $(SDIR)/objectmanager.cxx $(IDIR)/globals.h $(IDIR)/screen.h $(IDIR)/objectmanager.h $(IDIR)/object.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/bug.o: $(SDIR)/bug.cxx $(IDIR)/globals.h $(IDIR)/screen.h $(IDIR)/object.h $(IDIR)/bug.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/button.o: $(SDIR)/button.cxx $(IDIR)/globals.h $(IDIR)/screen.h $(IDIR)/object.h $(IDIR)/button.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o