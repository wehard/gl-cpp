#pragma once

#include <string>
#include <map>
#include <vector>
#include "texture.h"

struct CharInfo
{
	char c;
	int id;
	int x;
	int y;
	int width;
	int height;
	int xOffset;
	int yOffset;
	int xAdvance;
};

class BitmapFont
{
private:
	std::string fontName;
	std::map<char, CharInfo> characters;
	Texture *texture;
	std::string bitmapFilename;
	void readFontData(char *path);
public:
	BitmapFont(char *path);
	~BitmapFont();
	CharInfo getCharInfo(char c);
	std::vector<CharInfo> getCharInfo(std::string s);
};
