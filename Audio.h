#ifndef AUDIO_H
#define AUDIO_H

#include "includes.h"

/*
 **
 **	This is a very simple static class used for
 **  loading and playing audio (not music).
 **
 **	For music sf::Music should be used.
 **	I don't think that needs any abstraction.
 **
 */

class Audio {
public:
    /*
        Initializes buffers. Call on application start.
    */
    static void Init();

    /*
            Preload an audio clip for playing it later.
            Assign it a name to use with the Play function.

            If a file with the same name has already been loaded this
            does nothing.

            Returns true both if the file was loaded and
            if it was already loaded in a previous call.
     */
    static bool Load(std::string path, std::string name);

    /*
            Plays an audio clip.

            Returns a pointer to the sf::Sound
            for controlling playback or NULL if
            no clip was loaded with that name.
     */
    static sf::Sound * Play(std::string name);

    /*
            Unload everything
     */
    static void Cleanup();

private:
    static std::map<std::string, sf::SoundBuffer *> _s_Buffers;
    static sf::Sound * _s_Channels[256];
    static int _s_ChannelIndex;
};

#endif // AUDIO_H
