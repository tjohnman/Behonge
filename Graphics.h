#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "includes.h"

/*
**
**	This is a very simple static class used for
**  loading textures.
**
*/

class Graphics
{
public:
	/*
	Preload a texture.
	Assign it a name to use with GetTexture.

	If a file with the same name has already been loaded this
	does nothing.

	Returns true both if the file was loaded and
	if it was already loaded in a previous call.
	*/
	static bool Load(std::string path, std::string name);

	/*
	Returns a reference to the sf::Texture.
	Prints a warning to stdout if no image was loaded with that name.
	*/
	static sf::Texture &GetTexture(std::string name);

	/*
	Unload everything
	*/
	static void Cleanup();

private:
	static std::map<std::string, sf::Texture *> _s_Textures;
};

#endif // GRAPHICS_H
