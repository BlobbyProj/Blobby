#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include <string>
#include <map>
#ifdef OSX
#include <SDL2_mixer/SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif
#include "globals.h"

class MusicManager {
private:
    // Map holds music tracks, with their filenams as the keys
    std::map< std::string, Mix_Music* > tracks;
    // determines if music will be played
    bool silent;
    
public:
    // destructor for MusicManager - deletes instance of MusicManager object
    // pre-conditions  MusicManager exists
    // post-conditions MusicManager no longer exists and all the music is freed
    ~MusicManager();
    
    // adds a track to the tracks map
    // param filename is the filename for the track
    // pre-conditions music file exists at the given filename
    // post-conditions the track is loaded to ready to play
    void add_track(std::string filename);
    
    // plays the specified track
    // param filename of track that should be played
    // pre-conditions the music file has been added to tracks
    // post-conditions the correct music is playing
    void play(std::string filename);
    
    // pauses the currently playing music
    void pause();
    
    // stops the currently playing music
    void stop();
    
    // unpauses the music
    void resume();
    
    // sets muted to opposite value
    void toggle();
    
    void fade_in(std::string filename, int ms);
    
    void fade_out(int ms);
    
};

#endif
