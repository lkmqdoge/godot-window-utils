#ifndef WINDOW_UTILS_H
#define WINDOW_UTILS_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/classes/object.hpp>

namespace godot {

class WindowUtils : public Object {
	GDCLASS(WindowUtils, Object);
protected:
	static void _bind_methods();

public:
	WindowUtils();
	~WindowUtils();

	static void set_transparent(int64_t);
	static void clear_transparent(int64_t);
	static void taskbar_hide(int64_t);
	static void taskbar_show(int64_t);
};

}

#endif