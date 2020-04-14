#pragma once

#include <vector>

class TexturedQuad
{
private:
    std::vector<float> vertices;
    std::vector<float> uvs;
    std::vector<unsigned int> indices;

public:
    unsigned int vao_id;
    unsigned int vbo_id;
    unsigned int ebo_id;
    // unsigned int cb_id;
    // unsigned int nb_id;
    unsigned int uvb_id;

public:
    TexturedQuad(/* args */);
    ~TexturedQuad();
};
