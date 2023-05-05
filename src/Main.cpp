#include <SDL2/SDL.h>
#include <cstdio>
#include <cstdlib>
#include <BackendGraphics.h>

int main (int argc, char **argv)
{
	int ret = SDL_Init (SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER);
	if (ret < 0) {
		fprintf (stderr, "SDL_Init: %s\n", SDL_GetError ());
		exit (EXIT_FAILURE);
	}


	Graphics graphics;
	graphics.set_clear_color (0x4c, 0x4c, 0x4c, 0xff);
	graphics.set_clear_bits (CLEAR_BITS::COLOR);
	graphics.set_viewport (0, 0, 1024, 600);

	SDL_Event event;
	while (SDL_PollEvent (&event)) {
		graphics.clear_viewport ( );

		SDL_GL_SwapWindow (graphics.window);
		SDL_Delay (16);
	}
}
