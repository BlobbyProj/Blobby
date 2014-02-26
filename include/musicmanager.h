#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include <string>
#include <map>
#ifdef LINUX
#include <SDL2/SDL_mixer.h>
#else
#include <SDL2_mixer/SDL_mixer.h>
#endif


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
