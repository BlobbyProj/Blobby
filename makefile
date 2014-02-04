IDIR = include
SDIR = src
ODIR = obj
	
CC = g++
CFLAGS = -I$(IDIR)  -std=c++0x -g -I/Library/Frameworks/SDL2.framework/Headers
LFLAGS = -g
LIBS =

_OBJ = main.o globals.o levelmanager.o screenmanager.o texture.o objectmanager.o rectangle.o playercharacter.o button.o image.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ)) /Library/Frameworks/SDL2.framework/Versions/Current/SDL2

_DEP = sed -n '/include "/p' test.txt | sed 's/.*"\(.*\)".*/\1/'

main: $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)

$(ODIR)/main.o: $(SDIR)/main.cxx $(IDIR)/globals.h $(IDIR)/levelmanager.h $(IDIR)/screenmanager.h $(IDIR)/objectmanager.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/globals.o: $(SDIR)/globals.cxx $(IDIR)/globals.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/levelmanager.o: $(SDIR)/levelmanager.cxx $(IDIR)/globals.h $(IDIR)/levelmanager.h $(IDIR)/button.h $(IDIR)/image.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/screenmanager.o: $(SDIR)/screenmanager.cxx $(IDIR)/globals.h $(IDIR)/texture.h $(IDIR)/screenmanager.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/texture.o: $(SDIR)/texture.cxx $(IDIR)/globals.h $(IDIR)/texture.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/objectmanager.o: $(SDIR)/objectmanager.cxx $(IDIR)/globals.h $(IDIR)/screenmanager.h $(IDIR)/objectmanager.h $(IDIR)/rectangle.h $(IDIR)/object.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/rectangle.o: $(SDIR)/rectangle.cxx $(IDIR)/globals.h $(IDIR)/point.h $(IDIR)/rectangle.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/playercharacter.o: $(SDIR)/playercharacter.cxx $(IDIR)/globals.h $(IDIR)/screenmanager.h $(IDIR)/rectangle.h $(IDIR)/object.h $(IDIR)/playercharacter.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/button.o: $(SDIR)/button.cxx $(IDIR)/globals.h $(IDIR)/screenmanager.h $(IDIR)/rectangle.h $(IDIR)/object.h $(IDIR)/button.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/image.o: $(SDIR)/image.cxx $(IDIR)/globals.h $(IDIR)/screenmanager.h $(IDIR)/rectangle.h $(IDIR)/object.h $(IDIR)/image.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o