#include "Widget.h"
#include <EventSystem/EventSystem.h>

Widget::Widget ( )
{
	EventSystem& event_system = EventSystem::get_instance ( );

	event_system.list_widgets.push_back (this);
}

void Widget::set_size (uint32_t w, uint32_t h)
{
}

void Widget::render ( )
{
}
