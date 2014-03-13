Blobby
======

Group Project; a game.
Created by Katya Fomenko, Deanna Hartsook, Sam Heinz and Natasha Issayeva
Music composed by Cindy Shen

Hot Keys
-------------
Main Menu: enter to Play
Scoreboard: enter to Continue
p to pause
m to mute

========================
**To Run on Linux OS**

1. Make sure you have SDL2 Library, SDL2_Image, and SDL2_Mixer Installed (if not, see the downloading information section below).

2. Go into the main blobby directory that contains the makefile

3. Type "make OS=LINUX" (this should successfully compile the Blobby game)

4. Upon completion, the executable file will be inside of the bin directory

5. Open the bin directory, and run the file named "Blobby". 

	(This can be done by typing "./Blobby" into the terminal).


========================

**To Run on Mac OS**

1. Make sure you have SDL2, SDL2_Image, and SDL2_Mixer Libraries Installed (if not, see downloading information for Mac below).

2. Go into the main blobby directory that contains the makefile

3. Type "make OS=OSX (this should successfully compile the Blobby game)

4. Upon completion, the executable file will be inside of the bin directory

5. Open the bin directory ("cd bin") 

6. Type "./blobby" to run the executable

========================

**Downloading SDL2 for Linux**

1. To install SDL2 you can either download it from the mercurial repository online or through the source code archive.<br>
	*Note: I recommend using the source code: Step 3. *

	Regardless, you must first install some dependencies necessary for compiling SDL2:

	Command: sudo apt-get install build-essential xorg-dev libudev-dev libts-dev libgl1-mesa-dev libglu1-mesa-dev libasound2-dev libpulse-dev libopenal-dev libogg-dev libvorbis-dev libaudiofile-dev libpng12-dev libfreetype6-dev libusb-dev libdbus-1-dev zlib1g-dev libdirectfb-dev 

2. If you wish to download it through the mercurial respository (else go to Step 3)<br>
	a. Install mercurial<br>
		Command: sudo apt-get install mercurial<br>
	b. Download the SDL2 (Note: SDL2 will be downloaded into the directory you're using in the terminal)<br>
		Command: hg clone http://hg.libsdl.org/SDL<br>
	c. Go into the SDL directory and build & install the libs<br>
		Command: ./config<br>
		Command: make<br>
		Command: sudo make install<br>
	(Now Skip To Step 4 )		
	
3. If you wish to download it using the source code<br>
	a. Go to :  http://www.libsdl.org/download-2.0.php<br> 
	b. Download "SDL2-2.0.0.tar.gz"<br>
	c. Extract the archive (You can do this using tar)<br>
		Command: tar -xvzf SDL2-2.0.0.tar.gz<br>
	d. Then build & install the libs<br>
		Command: ./configure<br>
		Command: make<br>
		Command: sudo make install <br>
4. Make sure to update links and cache to the libraries<br>
	Command: sudo ldconfig<br>

*Note: If you want to remove all the installed SDL libraries* <br>
	Command: sudo apt-get purge libsdl* <br>
	Command: sudo apt-get autoremove --purge <br>
	 
=============================

**Downloading SDL2_image for Linux**

1. To install SDL2_image, go to https://www.libsdl.org/projects/SDL_image/ <br>
2. Download "SDL2_image-2.0.0.tar.gz"<br>
3. Extract the archive (You can do this using tar)<br>
	Command: tar -xvzf SDL2_image-2.0.0.tar.gz<br>
4. Then build & install the libs<br>
	Command: ./configure<br>
	Command: make<br>
	Command: sudo make install<br>
5. Make sure to update links and cache to the libraries<br>
	Comand: sudo ldconfig<br>
	
===============================
**Downloading SDL2_mixer for Linux**

1. To install SDL2_mixer, go to http://www.libsdl.org/projects/SDL_mixer/<br>
2. Download "SDL2_mixer-2.0.0.tar.gz"<br>
3. Extract the archive (You can do this using tar)<br>
	Command: tar -xvzf SDL2_mixer-2.0.0.tar.gz<br>
4. Then build & install the libs<br>
	Command: ./configure<br>
	Command: make<br>
	Command: sudo make install<br>
5. Make sure to update links and cache to the libraries<br>
	Comand: sudo ldconfig<br>

===============================
**Downloading Frameworks for Mac**

1. Download SDL2 from http://libsdl.org/download-2.0.php

2. Download SDL2_image from https://www.libsdl.org/projects/SDL_image/

3. Download SDL2_mixer from http://www.libsdl.org/projects/SDL_mixer/

4. Download SDL_ttf from https://www.libsdl.org/projects/SDL_ttf/ 

5. Install and save all four frameworks in /Library/Frameworks (you can use command-g to get to the folder)





