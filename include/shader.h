#include <GL/glew.h>
#include <iostream>
#include <map>

using namespace std;

class shader
{
private:
	GLuint	p_id;
	GLuint	v_id;
	GLuint	f_id;
	string	vert_path;
	string	frag_path;
	std::map<string, GLuint> uniforms;
	std::map<string, GLuint> attributes;

	string load_shader(string path);
	GLuint compile_shader(string src, GLenum shader_type);
	GLuint create_program(GLuint vert_id, GLuint frag_id);
	void load_uniforms();
	void load_attributes();
public:
	shader(string vert_path, string frag_path);
	~shader();
	void use();

};

