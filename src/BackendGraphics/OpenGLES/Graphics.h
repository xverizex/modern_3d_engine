#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <GLES3/gl3.h>
#include <cstdint>

enum class CLEAR_BITS {
	COLOR,
	DEPTH,
	N_CLEAR_BITS
};

class Graphics {
	public:
		Graphics ();
		void set_clear_bits (CLEAR_BITS);
		void clear_viewport ( );
		void set_clear_color (uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		void set_viewport (int32_t x, int32_t y, uint32_t width, uint32_t height);
		
		SDL_Window *window;
		SDL_GLContext ctx;
	protected:
		uint32_t clear_flags = 0;
		float clear_color[4];
};

#endif
