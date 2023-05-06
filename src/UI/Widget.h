#ifndef WIDGET_H
#define WIDGET_H

#include <cstdint>
#include <BackendGraphics.h>

class EventSystem;

class Widget {
	public:
		Widget ();
	protected:
		virtual void set_size (uint32_t w, uint32_t h);
		virtual void render ( );

		Object2d *object;

	friend class EventSystem;
};

#endif
