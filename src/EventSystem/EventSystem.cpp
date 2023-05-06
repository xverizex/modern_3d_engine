#include "EventSystem.h"

EventSystem &EventSystem::get_instance ( )
{
	static EventSystem singleton;
	return singleton;
}

EventSystem::EventSystem ()
{
}

void EventSystem::set_graphics_backend (Graphics& _graphics)
{
	graphics = &_graphics;
}

void EventSystem::handle_events ( )
{
	uint32_t size = list_widgets.size ();
	for (uint32_t i = 0; i < size; i++) {

		list_widgets[i]->render ( );
	}
}
