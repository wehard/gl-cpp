#include "bitmap_font.h"
#include <fstream>

BitmapFont::BitmapFont(char *path)
{
	readFontData(path);
	texture = new Texture("resources/classic_console.png");
}

BitmapFont::~BitmapFont()
{
}

CharInfo BitmapFont::getCharInfo(char c)
{
	// std::map<char, CharInfo>::iterator it = characters.find(c);
	// if (it != characters.end())
	return (characters[c]);
}

std::vector<CharInfo> BitmapFont::getCharInfo(std::string s)
{
	std::vector<CharInfo> charInfos;

	for (char &c : s)
	{
		std::map<char, CharInfo>::iterator it = characters.find(c);
		if (it != characters.end())
		{
			charInfos.push_back(characters[c]);
		}
	}
	return (charInfos);
}

void BitmapFont::readFontData(char *path)
{
	std::ifstream file(path);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			if (line.compare(0, 4, "info") == 0)
			{
				fontName = "Font Name";
			}
			else if (line.compare(0, 6, "common") == 0)
			{
			}
			else if (line.compare(0, 6, "page") == 0)
			{
			}
			else if (line.compare(0, 5, "chars") == 0)
			{
			}
			else if (line.compare(0, 4, "char") == 0)
			{
				CharInfo info;
				sscanf(line.c_str(),
					   "char id=%d x=%d y=%d width=%d height=%d xoffset=%d yoffset=%d xadvance=%d",
					   &info.id, &info.x, &info.y, &info.width, &info.height, &info.xOffset, &info.yOffset, &info.xAdvance);
				info.c = (char)info.id;
				characters[info.c] = info;
			}
		}
		file.close();
	}
}

Texture *BitmapFont::getTexture()
{
	return (texture);
}