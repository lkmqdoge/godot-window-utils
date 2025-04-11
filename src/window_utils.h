#ifndef WINDOW_UTILS_H
#define WINDOW_UTILS_H

#include <godot_cpp/classes/window.hpp>

namespace godot {

class WindowUtils : public Object {
	GDCLASS(WindowUtils, Object)
protected:
	static void _bind_methods();

public:
	WindowUtils();
	~WindowUtils();

	static void set_layered(Window);
	static bool get_layered(Window);
};

}

#endif