#include "musicmanager.h"

#include "globals.h"

// Instance of this object will hold and control the music

MusicManager::~MusicManager()
{
    std::map<std::string,Mix_Music*>::iterator it;
	for (it = tracks.begin(); it != tracks.end(); ++it)
	{
		Mix_FreeMusic(it->second);
	}
	tracks.clear();
}

void MusicManager::add_track(std::string filename)
{
    Mix_Music * m = Mix_LoadMUS( filename.c_str());
    if (m == NULL)
        MARK
    tracks[filename] = m;
}

void MusicManager::play(std::string filename, int loops)
{
    // -1 says to loop music
    if (Mix_PlayMusic( tracks[filename], loops ) != 0)
    {
        MARK
    }
    while(Mix_PlayingMusic()==0);
    if (muted)
        pause();
}

void MusicManager::pause()
{
    Mix_PauseMusic();
}

void MusicManager::stop()
{
    Mix_HaltMusic();
}

void MusicManager::resume()
{
    if (!muted)
        Mix_ResumeMusic();
}

void MusicManager::toggle()
{
    if (muted) {
        muted = false;
        resume();
        
    }
    else {
        muted = true;
        pause();
    }
}

void MusicManager::fade_in(std::string filename, int ms)
{
    Mix_FadeInMusic(tracks[filename], -1, ms);
}

void MusicManager::fade_out(int ms)
{
    Mix_FadeOutMusic(ms);
}
