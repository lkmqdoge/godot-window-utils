#include "window_utils.h"
#include <godot_cpp/core/class_db.hpp>
#include <windows.h>
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/classes/display_server.hpp>

using namespace godot;

void WindowUtils::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_layered", "window"), &WindowUtils::set_layered);
	ClassDB::bind_method(D_METHOD("get_layered", "window"), &WindowUtils::get_layered);
}

WindowUtils::WindowUtils() {

}

WindowUtils::~WindowUtils() {
	// Add your cleanup here.
}

void WindowUtils::set_layered(Window window){
	HWND hwnd = (HWND)(LONG_PTR)DisplayServer::get_singleton()->window_get_native_handle(DisplayServer::WINDOW_HANDLE);
	if (!hwnd) return;
	
	LONG style = GetWindowLong(hwnd, GWL_EXSTYLE);
	SetWindowLong(hwnd, GWL_EXSTYLE, style | WS_EX_LAYERED);

	SetLayeredWindowAttributes(hwnd, 0, 0, LWA_COLORKEY);
}

bool WindowUtils::get_layered(Window window){
	return false;
}