#include "GL/glew.h"
#include "text.h"
#include "mesh.h"
#include "bitmap_font.h"
#include "glm/vec3.hpp"

Text::Text(BitmapFont *font, std::string str) : str(str), font(font)
{
	this->mesh = new Mesh();
	generateMesh();
	genBuffers();
}

Text::~Text()
{
}

void Text::generateMesh()
{
	float xOffset = 0.0f;
	std::vector<CharInfo> charInfos = font->getCharInfo(this->str);
	int i = 0;
	for (CharInfo &c : charInfos)
	{
		Texture *texture = font->getTexture();
		float charWidth = (float)c.width / (float)texture->width;
		float charHeight = (float)c.height / (float)texture->height;
		float charXOffset = (float)c.xOffset / (float)texture->width;
		float xAdvance = (float)c.xAdvance / texture->width;


		std::vector<float> verts = {
			xOffset, 0.0f, 0.0f,
			xOffset, charHeight, 0.0f,
			xOffset + charWidth, charHeight, 0.0f,
			xOffset + charWidth, 0.0f, 0.0f
		};

		mesh->vertices.insert(mesh->vertices.end(), verts.begin(), verts.end());

		std::vector<int> indices = {
			(i * 4) + 0,
			(i * 4) + 1,
			(i * 4) + 2,
			(i * 4) + 0,
			(i * 4) + 2,
			(i * 4) + 3	
		};

		mesh->indices.insert(mesh->indices.end(), indices.begin(), indices.end());

		float charX = (float)c.x / texture->width;
		float charY = (float)c.y / texture->height;

		std::vector<float> uvs = {
			charX, 1.0f - (charY + charHeight),
			charX, 1.0f - charY,
			charX + charWidth, 1.0f - charY,
			charX + charWidth, 1.0f - (charY + charHeight)
		};

		mesh->uvs.insert(mesh->uvs.end(), uvs.begin(), uvs.end());


		std::vector<float> colors = {
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
		};
		mesh->colors.insert(mesh->colors.end(), colors.begin(), colors.end());

		std::vector<float> normals = {
			0.0f, 0.0f, -1.0f,
			0.0f, 0.0f, -1.0f,
			0.0f, 0.0f, -1.0f,
			0.0f, 0.0f, -1.0f,
		};
		mesh->normals.insert(mesh->normals.end(), normals.begin(), normals.end());


		xOffset += (xAdvance + charXOffset);
		i++;
	}
}

BitmapFont *Text::getFont()
{
	return (font);
}