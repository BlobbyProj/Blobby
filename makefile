NAME = Blobby

IDIR = include
SDIR = src
ODIR = obj
BDIR = bin
	
CC = g++
OS = 

_OBJ = main.o globals.o console.o levelmanager.o screenmanager.o texture.o objectmanager.o rectangle.o playercharacter.o button.o image.o enemy.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

vpath %.h $(IDIR)
vpath %.cxx $(SDIR)

#Check: if Windows or Linux, set _libs
ifeq ($(OS),Windows_NT)
	_libs = -lmingw32 -lSDL2main -lSDL2 -mwindows
else
	_libs = -lSDL2
endif

ifeq ($(OS),OSX)
#MAC
CFLAGS = -I$(IDIR) -std=c++0x -g -I/Library/Frameworks/SDL2.framework/Headers
LFLAGS = -g
LIBS =
FRAMEWORKS = /Library/Frameworks/SDL2.framework/Versions/Current/SDL2
else

#WINDOWS/Linux
CFLAGS = -I$(IDIR) -std=c++0x -g
LFLAGS = -static-libgcc -static-libstdc++ -g
LIBS = $(_libs)
FRAMEWORKS = 
endif

_DEP = sed -n '/include "/p' test.txt | sed 's/.*"\(.*\)".*/\1/'

$(BDIR)/$(NAME): $(OBJ) $(FRAMEWORKS)
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)

$(ODIR)/main.o: main.cxx globals.h levelmanager.h screenmanager.h objectmanager.h console.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/globals.o: globals.cxx globals.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/console.o: console.cxx globals.h console.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/levelmanager.o: levelmanager.cxx globals.h levelmanager.h button.h image.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/screenmanager.o: screenmanager.cxx globals.h texture.h screenmanager.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/texture.o: texture.cxx globals.h texture.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/objectmanager.o: objectmanager.cxx globals.h screenmanager.h objectmanager.h rectangle.h object.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/rectangle.o: rectangle.cxx globals.h point.h rectangle.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/playercharacter.o: playercharacter.cxx globals.h screenmanager.h rectangle.h object.h playercharacter.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/button.o: button.cxx globals.h screenmanager.h rectangle.h object.h button.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/image.o: image.cxx globals.h screenmanager.h rectangle.h object.h image.h
	$(CC) -c -o $@ $< $(CFLAGS)
    
$(ODIR)/enemy.o: enemy.cxx globals.h screenmanager.h rectangle.h object.h enemy.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
.PHONY: clean
	
clean:
ifeq ($(OS),OSX)
#MAC
	rm -f $(ODIR)/*.o
else
#WINDOWS
	del $(ODIR)\*.o
endif
