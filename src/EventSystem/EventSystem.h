#ifndef EVENT_SYSTEM_H
#define EVENT_SYSTEM_H
#include <vector>
#include <cstdint>
#include <UI/Widget.h>
#include <BackendGraphics.h>

class EventSystem {
	public:
		static EventSystem &get_instance ();
		void set_graphics_backend (Graphics&);
		void handle_events ( );

		std::vector<Widget *> list_widgets;
	private:
		EventSystem ();

		Graphics* graphics;
};

#endif
