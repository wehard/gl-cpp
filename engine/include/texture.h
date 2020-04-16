#pragma once

class Texture
{
private:
	unsigned int tex_id;
public:
	int width;
	int height;
	Texture(int width, int height);
	Texture(char *path);
	~Texture();
	unsigned int getTextureID();
};

