Blobby
======

Group Project; a game.

========================
To Run on Linux OS

1. Make sure you have SDL2 Library Installed (if not, see 'downloading SDL2 for Linux below').

2. Go into the main blobby directory that contains the makefile

3. Type "make OS=LINUX" (this should successfully compile the Blobby game)

4. Upon completion, the executable file will be inside of the bin directory

5. Open the bin directory, and run the file named "Blobby". 

	(This can be done by typing "./Blobby" into the terminal).


========================

To Run on Mac OS


========================

To Run on Windows OS



===============================

Downloading SDL2 for Linux

1. To install SDL2 you can either download it from the mercurial repository online or through the source code archive.
	Regardless, you must first install some dependencies necessary for compiling SDL2:

	Command: sudo apt-get install build-essential xorg-dev libudev-dev libts-dev libgl1-mesa-dev libglu1-mesa-dev libasound2-dev libpulse-dev libopenal-dev libogg-dev libvorbis-dev libaudiofile-dev libpng12-dev libfreetype6-dev libusb-dev libdbus-1-dev zlib1g-dev libdirectfb-dev 

2. If you wish to download it through the mercurial respository (else go to Step 3)
	a. Install mercurial
		Command: sudo apt-get install mercurial
	b. Download the SDL2 (Note: SDL2 will be downloaded into the directory you're using in the terminal)
		Command: hg clone http://hg.libsdl.org/SDL
	c. Go into the SDL directory and build & install the libs
		Command: ./config
		Command: make
		Command: sudo make install
	(Now Skip To Step 4 )		
	
3. If you wish to download it using the source code
	a. Go to :  http://www.libsdl.org/download-2.0.php 
	b. Download "SDL2-2.0.0.tar.gz"
	c. Extract the archive (You can do this using tar)
		Command: tar -xvzf SDL2-2.0.0.tar.gz
	d. Then build & install the libs
		Command: ./configure
		Command: make
		Command: sudo make install 
4. Make sure to update links and cache to the libraries
	Command: sudo ldconfig

**Note: If you want to remove all the installed SDL libraries
	Command: sudo apt-get purge libsdl*
	Command: sudo apt-get autoremove --purge 
