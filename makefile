NAME = Blobby

IDIR = include
SDIR = src
ODIR = obj
BDIR = bin
	
CC = g++
OS = 

_OBJ = main.o globals.o levelmanager.o screenmanager.o texture.o gloop.o objectmanager.o object.o rectangle.o playercharacter.o button.o image.o enemy.o block.o flag.o musicmanager.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

OBJECTS = playercharacter.h button.h image.h enemy.h block.h flag.h gloop.h

vpath %.h $(IDIR)
vpath %.cxx $(SDIR)

#OSX
ifeq ($(OS),OSX)
CFLAGS = -I$(IDIR) -std=c++0x -g -DOSX
LFLAGS = -g
LIBS =
FRAMEWORKS = /Library/Frameworks/SDL2.framework/Versions/Current/SDL2 /Library/Frameworks/SDL2_image.framework/Versions/Current/SDL2_image /Library/Frameworks/SDL2_mixer.framework/Versions/Current/SDL2_mixer
endif

#WINDOWS
ifeq ($(OS),WINDOWS)
CFLAGS = -I$(IDIR) -std=c++0x -g -DWINDOWS
LFLAGS = -static-libgcc -static-libstdc++ -g -lSDL2_mixer
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -mwindows
FRAMEWORKS = 
endif

#LINUX
ifeq ($(OS),LINUX)
CFLAGS = -I$(IDIR) -std=c++0x -g -DLINUX
LFLAGS = -static-libgcc -static-libstdc++ -g
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer
FRAMEWORKS = 
endif

_DEP = sed -n '/include "/p' test.txt | sed 's/.*"\(.*\)".*/\1/'

$(BDIR)/$(NAME): $(OBJ) $(FRAMEWORKS)
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)

$(ODIR)/main.o: main.cxx globals.h levelmanager.h screenmanager.h objectmanager.h musicmanager.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/globals.o: globals.cxx globals.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/levelmanager.o: levelmanager.cxx globals.h levelmanager.h screenmanager.h objectmanager.h musicmanager.h $(OBJECTS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/screenmanager.o: screenmanager.cxx globals.h levelmanager.h screenmanager.h texture.h rectangle.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/objectmanager.o: objectmanager.cxx globals.h screenmanager.h objectmanager.h rectangle.h object.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/musicmanager.o: musicmanager.cxx globals.h musicmanager.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/texture.o: texture.cxx globals.h texture.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/rectangle.o: rectangle.cxx globals.h point.h rectangle.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/object.o: object.cxx globals.h levelmanager.h screenmanager.h point.h rectangle.h object.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/playercharacter.o: playercharacter.cxx globals.h screenmanager.h objectmanager.h musicmanager.h object.h playercharacter.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/button.o: button.cxx globals.h screenmanager.h object.h button.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/image.o: image.cxx globals.h screenmanager.h object.h image.h
	$(CC) -c -o $@ $< $(CFLAGS)
    
$(ODIR)/enemy.o: enemy.cxx globals.h screenmanager.h object.h enemy.h
	$(CC) -c -o $@ $< $(CFLAGS)
    
$(ODIR)/block.o: block.cxx globals.h screenmanager.h object.h block.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/flag.o: flag.cxx globals.h screenmanager.h object.h flag.h
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/gloop.o: gloop.cxx globals.h screenmanager.h object.h gloop.h
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
	
clean:
ifeq ($(OS),WINDOWS)
	del $(ODIR)\*.o
else
	rm -f $(ODIR)/*.o
endif
