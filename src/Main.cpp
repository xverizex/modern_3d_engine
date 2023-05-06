#include <SDL2/SDL.h>
#include <cstdio>
#include <cstdlib>
#include <BackendGraphics.h>
#include <EventSystem/EventSystem.h>

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

	EventSystem& event_system = EventSystem::get_instance ( );
	event_system.set_graphics_backend (graphics);


	SDL_Event event;
	while (SDL_PollEvent (&event)) {
		graphics.clear_viewport ( );

		event_system.handle_events ( );

		SDL_GL_SwapWindow (graphics.window);
		SDL_Delay (16);
	}
}
