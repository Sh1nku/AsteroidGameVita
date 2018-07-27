#ifndef DEBUG
#include "utils.h"
#include "headers.h"

GLuint loadTexture(const char* name) {
	glEnable(GL_TEXTURE_2D);
	std::string filename = "app0:/";
	filename += name;
	glEnable(GL_TEXTURE_2D);
	SDL_Surface *textureSurface = IMG_Load(filename.c_str());
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureSurface->w, textureSurface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureSurface->pixels);
	SDL_FreeSurface(textureSurface);	
	return texture;
}
#endif
