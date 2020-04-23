#pragma once
#include "GL/glew.h"
#include <iostream>
#include <map>
#include <glm/glm.hpp>

namespace wgl
{

class Shader
{
private:
	unsigned int p_id;
	unsigned int v_id;
	unsigned int f_id;
	std::string vert_path;
	std::string frag_path;
	std::map<std::string, unsigned int> uniforms;
	std::map<std::string, unsigned int> attributes;

	std::string loadShader(std::string path);
	unsigned int compileShader(std::string src, GLenum shader_type);
	unsigned int createProgram(unsigned int vert_id, unsigned int frag_id);
	void loadUniforms();
	void loadAttributes();

public:
	Shader();
	Shader(std::string vert_path, std::string frag_path);
	~Shader();
	void use();
	void setFloat(std::string name, float f);
	void setVec2(std::string name, glm::vec2 v);
	void setVec3(std::string name, glm::vec3 v);
	void setMat4(std::string name, glm::mat4x4 m);
};

} // namespace wgl