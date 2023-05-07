#ifndef SHADER_H
#define SHADER_H

#include <cstdint>
#include <string>
#include <vector>
#include "ObjectShader.h"
#include <DefaultListShader.h>

class Shader {
	public:
		static Shader& get_instance ();
		void set_max_shaders (uint32_t size);
		void add_shader (uint32_t index, std::string name);

		ObjectShader* get_shader (uint32_t index);
	protected:
		uint32_t create_program (std::string &name);
		uint32_t create_shader (uint32_t type, std::string &name);
		std::vector<ObjectShader *> list_programs;
	private:
		Shader ();
};

#endif
