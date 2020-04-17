#pragma once

#include <string>
#include "entity.h"
#include "bitmap_font.h"

class Mesh;

class Text : public Entity
{
private:
	std::string str;
	BitmapFont *font;
	void generateMesh();
public:
	Text(BitmapFont *font, std::string str);
	// void draw() override;
	BitmapFont *getFont();
	~Text();
};


