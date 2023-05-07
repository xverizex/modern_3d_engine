#include "Shader.h"
#include <unistd.h>
#include <iostream>
#include <GLES3/gl3.h>

Shader::Shader ( )
{
}

Shader& Shader::get_instance ( )
{
	static Shader singleton;
	return singleton;
}

void Shader::set_max_shaders (uint32_t size)
{
	list_programs.resize (size);
}

void Shader::add_shader (uint32_t index, std::string name)
{
	if (index >= list_programs.size())
		std::cerr << "index shader too big than size of the list shader: index == " << index << "; size list == " << list_programs.size () << std::endl;
		exit (0); // TODO display message about that index is exceed the size of vector shader list.


	uint32_t program = create_program (name);
}

ObjectShader* Shader::get_shader (uint32_t index)
{
	if (index >= list_programs.size())
		return 0;

	return list_programs[index];
}

uint32_t Shader::create_program (std::string &name)
{
	uint32_t vert = create_shader (GL_VERTEX_SHADER, name);
	uint32_t frag = create_shader (GL_FRAGMENT_SHADER, name);

	return 0; // TODO implement link program
}

uint32_t Shader::create_shader (uint32_t type, std::string &name)
{
	std::string path = "assets/";

	switch (type) {
		case GL_VERTEX_SHADER:
			path += name + ".vert";
			break;
		case GL_FRAGMENT_SHADER:
			path += name + ".frag";
			break;
		default:
			break;
	}

	if (access (path.c_str (), F_OK)) {
		std::cerr << "path of shader: " << path << ": not found" << std::endl;
		exit (0); //TODO display error
	}

	return 0; // TODO implement compile shader
}
