#pragma once

#include <string>
#include "entity.h"
#include "bitmap_font.h"

namespace wgl
{

class Mesh;

class Text : public Entity
{
private:
	std::string str;
	BitmapFont *font;
	void generateMesh();

public:
	Text();
	Text(BitmapFont *font, std::string str);
	void draw() override;
	BitmapFont *getFont();
	~Text();
	void setText(std::string text);
};

} // namespace wgl