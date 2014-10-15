#include "Graphics.h"

std::map<std::string, sf::Texture *> Graphics::_s_Textures;

bool Graphics::Load(std::string path, std::string name)
{
	std::map<std::string, sf::Texture *>::iterator it;
	it = _s_Textures.find(name);
	if (it == _s_Textures.end())
	{
		sf::Texture * buffer = new sf::Texture();

		if (buffer->loadFromFile(path))
		{
			_s_Textures[name] = buffer;
			return true;
		}
		else
			return false;
	}

	return true;
}

sf::Texture &Graphics::GetTexture(std::string name)
{
	std::map<std::string, sf::Texture *>::iterator it;
	it = _s_Textures.find(name);
	if (it == _s_Textures.end())
	{
		std::cout << "Texture \"" << name << "\" was not found.\n";
	}

	return *it->second;
}

void Graphics::Cleanup()
{
	std::map<std::string, sf::Texture *>::iterator it;
	for (it = _s_Textures.begin(); it != _s_Textures.end(); ++it)
	{
		delete it->second;
	}
	_s_Textures.clear();
}
