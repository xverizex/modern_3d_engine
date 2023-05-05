#include "Graphics.h"

Graphics::Graphics ( )
{
	SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute (SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
	SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, 1);

	uint32_t flags_window = SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL;

	window = SDL_CreateWindow ("modern 3d engine",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			1024, 600,
			flags_window
			);

	ctx = SDL_GL_CreateContext (window);
}

void Graphics::set_clear_bits (CLEAR_BITS bits)
{
	clear_flags = 0;

	uint32_t _bits = static_cast<uint32_t>(bits);
	uint32_t _color = static_cast<uint32_t>(CLEAR_BITS::COLOR);
	uint32_t _depth = static_cast<uint32_t>(CLEAR_BITS::DEPTH);


	if (_bits & _color)
		clear_flags |= GL_COLOR_BUFFER_BIT;
	if (_bits & _depth) 
		clear_flags |= GL_DEPTH_BUFFER_BIT;
}

void Graphics::set_clear_color (uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	clear_color[0] = red / 255.f;
	clear_color[1] = green / 255.f;
	clear_color[2] = blue / 255.f;
	clear_color[3] = alpha / 255.f;
}

void Graphics::clear_viewport ( )
{
	glClearColor (
			clear_color[0],
			clear_color[1],
			clear_color[2],
			clear_color[3]
		     );

	glClear (clear_flags);
}

void Graphics::set_viewport (int32_t x, int32_t y, uint32_t width, uint32_t height)
{
	glViewport (x, y, width, height);
}
