#pragma once
#include <GL/glew.h>
#include <iostream>
#include <map>
#include <glm/glm.hpp>

namespace wgl
{

class Shader
{
private:
	GLuint p_id;
	GLuint v_id;
	GLuint f_id;
	std::string vert_path;
	std::string frag_path;
	std::map<std::string, GLuint> uniforms;
	std::map<std::string, GLuint> attributes;

	std::string loadShader(std::string path);
	GLuint compileShader(std::string src, GLenum shader_type);
	GLuint createProgram(GLuint vert_id, GLuint frag_id);
	void loadUniforms();
	void loadAttributes();

public:
	Shader(std::string vert_path, std::string frag_path);
	~Shader();
	void use();
	void setFloat(std::string name, float f);
	void setVec2(std::string name, glm::vec2 v);
	void setVec3(std::string name, glm::vec3 v);
	void setMat4(std::string name, glm::mat4x4 m);
};

} // namespace wgl