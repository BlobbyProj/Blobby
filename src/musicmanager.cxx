#include "musicmanager.h"

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

void MusicManager::play(std::string filename, int loop)
{
    if ( !loaded(filename) )
    {
        add_track(filename);
    }
    // -1 says to loop music
    if (Mix_PlayMusic( tracks[filename], loop ) != 0)
    {
        MARK
    }
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
    if ( !loaded(filename) )
    {
        add_track(filename);
    }
    Mix_FadeInMusic(tracks[filename], -1, ms);
    if (muted)
        pause();
}

void MusicManager::fade_out(int ms)
{
    Mix_FadeOutMusic(ms);
}

bool MusicManager::loaded(std::string name)
{
    if ( tracks.find(name) != tracks.end() ) {
        return true;
    } else {
        return false;
    }
}
