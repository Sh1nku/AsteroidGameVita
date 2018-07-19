#ifndef DEBUG
#include "utils.h"
#include "headers.h"

GLuint loadTexture(const char* name) {
	std::string filename = "app0:/";
	filename += name;
	vita2d_texture* v2d_texture = vita2d_load_PNG_file(filename.c_str());
	int width = vita2d_texture_get_width(v2d_texture);
	int height = vita2d_texture_get_height(v2d_texture);
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, vita2d_texture_get_datap(v2d_texture));
	return texture;
}
#endif
