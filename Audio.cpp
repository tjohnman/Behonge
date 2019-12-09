#include "Audio.h"

std::map<std::string, sf::SoundBuffer *> Audio::_s_Buffers;
sf::Sound * Audio::_s_Channels[256];
int Audio::_s_ChannelIndex;

void Audio::Init() {
	for(unsigned i=0; i<256; ++i) {
		Audio::_s_Channels[i] = new sf::Sound();
	}
}

bool Audio::Load(std::string path, std::string name)
{
	std::map<std::string, sf::SoundBuffer *>::iterator it;
	it = _s_Buffers.find(name);
	if(it == _s_Buffers.end())
	{
		sf::SoundBuffer * buffer = new sf::SoundBuffer();

		if(buffer->loadFromFile(path))
		{
			_s_Buffers[name] = buffer;
			return true;
		}
		else
			return false;
	}

	return true;
}

sf::Sound * Audio::Play(std::string name)
{
	std::map<std::string, sf::SoundBuffer *>::iterator it;
	it = _s_Buffers.find(name);
	if(it == _s_Buffers.end())
	{
		return 0;
	}

	sf::Sound * sound = Audio::_s_Channels[_s_ChannelIndex++%256];

	sound->stop();
	sound->setBuffer(*it->second);
	sound->play();

	return sound;
}

void Audio::Cleanup()
{
	std::map<std::string, sf::SoundBuffer *>::iterator it;
	for(it=_s_Buffers.begin(); it!=_s_Buffers.end(); ++it)
	{
		delete it->second;
	}
	_s_Buffers.clear();

	for(unsigned i=0; i<256; ++i) {
		delete Audio::_s_Channels[i];
	}
}
