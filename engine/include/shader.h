#pragma once
#include <GL/glew.h>
#include <iostream>
#include <map>
#include <glm/glm.hpp>

using namespace std;

class Shader
{
private:
	GLuint	p_id;
	GLuint	v_id;
	GLuint	f_id;
	string	vert_path;
	string	frag_path;
	std::map<string, GLuint> uniforms;
	std::map<string, GLuint> attributes;

	string loadShader(string path);
	GLuint compileShader(string src, GLenum shader_type);
	GLuint createProgram(GLuint vert_id, GLuint frag_id);
	void loadUniforms();
	void loadAttributes();
public:
	Shader(string vert_path, string frag_path);
	~Shader();
	void use();
	void setFloat(string name, float f);
	void setVec2(string name, glm::vec2 v);
	void setVec3(string name, glm::vec3 v);
	void setMat4(string name, glm::mat4x4 m);
};
