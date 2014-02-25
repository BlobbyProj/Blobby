#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include <string>
#include <map>

#include <SDL2_mixer/SDL_mixer.h>

class MusicManager {
private:
    // Map holds music tracks, with their filenams as the keys
    std::map< std::string, Mix_Music* > tracks;
    
public:
    ~MusicManager();
    void add_track(std::string filename);
    void play(std::string filename);
    void pause();
    void stop();
    void resume();
    
};

#endif