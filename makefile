IDIR = include
SDIR = src
ODIR = obj
	
CC = g++
CFLAGS = -I$(IDIR)  -std=c++0x -g
LFLAGS = -static-libgcc -static-libstdc++ -g
LIBS = -lmingw32 -lSDLmain -lSDL

_OBJ = main.o globals.o levelmanager.o screenmanager.o surface.o objectmanager.o playercharacter.o button.o sprite.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_DEP = sed -n '/include "/p' test.txt | sed 's/.*"\(.*\)".*/\1/'

main: $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)

$(ODIR)/main.o: $(SDIR)/main.cxx $(IDIR)/globals.h $(IDIR)/levelmanager.h $(IDIR)/screenmanager.h $(IDIR)/objectmanager.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/globals.o: $(SDIR)/globals.cxx $(IDIR)/globals.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/levelmanager.o: $(SDIR)/levelmanager.cxx $(IDIR)/globals.h $(IDIR)/levelmanager.h $(IDIR)/button.h $(IDIR)/sprite.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/screenmanager.o: $(SDIR)/screenmanager.cxx $(IDIR)/globals.h $(IDIR)/surface.h $(IDIR)/screenmanager.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/surface.o: $(SDIR)/surface.cxx $(IDIR)/globals.h $(IDIR)/surface.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/objectmanager.o: $(SDIR)/objectmanager.cxx $(IDIR)/globals.h $(IDIR)/screenmanager.h $(IDIR)/objectmanager.h $(IDIR)/object.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/playercharacter.o: $(SDIR)/playercharacter.cxx $(IDIR)/globals.h $(IDIR)/screenmanager.h $(IDIR)/object.h $(IDIR)/playercharacter.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/button.o: $(SDIR)/button.cxx $(IDIR)/globals.h $(IDIR)/screenmanager.h $(IDIR)/object.h $(IDIR)/button.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/sprite.o: $(SDIR)/sprite.cxx $(IDIR)/globals.h $(IDIR)/screenmanager.h $(IDIR)/object.h $(IDIR)/sprite.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o