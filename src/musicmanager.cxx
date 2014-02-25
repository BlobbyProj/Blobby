#include "musicmanager.h"
#include "globals.h"

// Instance of this object will hold and control the music

MusicManager::~MusicManager(){
    std::map<std::string,Mix_Music*>::iterator it;
	for (it = tracks.begin(); it != tracks.end(); ++it)
	{
		Mix_FreeMusic(it->second);
	}
	tracks.clear();
}

void MusicManager::add_track(std::string filename){
    Mix_Music * m = Mix_LoadMUS( filename.c_str());
    if (m == NULL)
        FLAG
    tracks[filename] = m;
}

void MusicManager::play(std::string filename){
    // -1 says to loop music
    if (Mix_PlayMusic( tracks[filename], -1 ) != 0){
        FLAG
    }
}
void MusicManager::pause(){
    Mix_PauseMusic();
}
void MusicManager::stop(){
    Mix_HaltMusic();
}

void MusicManager::resume(){
    Mix_ResumeMusic();
}
