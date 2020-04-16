#pragma once

#include <string>

class Mesh;
class BitmapFont;

class Text
{
private:
	std::string str;
	BitmapFont *font;
	Mesh *mesh;
	void generateMesh();
public:
	Text(BitmapFont *font, std::string str);
	~Text();
};


