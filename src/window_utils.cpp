#include "window_utils.h"
#include <godot_cpp/core/class_db.hpp>
#include <windows.h>
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/classes/display_server.hpp>

using namespace godot;

void WindowUtils::_bind_methods() {
	ClassDB::bind_static_method("WindowUtils", D_METHOD("set_transparent"), &WindowUtils::set_transparent);
	ClassDB::bind_static_method("WindowUtils", D_METHOD("clear_transparent"), &WindowUtils::clear_transparent);
	ClassDB::bind_static_method("WindowUtils", D_METHOD("taskbar_hide"), &WindowUtils::taskbar_hide);
	ClassDB::bind_static_method("WindowUtils", D_METHOD("taskbar_show"), &WindowUtils::taskbar_show);
}

WindowUtils::WindowUtils() {

}

WindowUtils::~WindowUtils() {
	// Add your cleanup here.
}

void WindowUtils::set_transparent(int64_t hwnd){
	if (!hwnd) return;
	HWND hWnd = (HWND)(LONG_PTR)hwnd;
	LONG style = GetWindowLong(hWnd, GWL_EXSTYLE);
	SetWindowLong(hWnd, GWL_EXSTYLE, style | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hWnd, 0, 0, LWA_COLORKEY);
}

void WindowUtils::clear_transparent(int64_t hwnd){
	if (!hwnd) return;
	HWND hWnd = (HWND)(LONG_PTR)hwnd;
	SetLayeredWindowAttributes(hWnd, 0, 0, 0);
	LONG style = GetWindowLong(hWnd, GWL_EXSTYLE);
	SetWindowLong(hWnd, GWL_EXSTYLE, style & ~WS_EX_LAYERED);
}

void WindowUtils::taskbar_hide(int64_t hwnd){
	if (!hwnd) return;
	HWND hWnd = (HWND)(LONG_PTR)hwnd;
	LONG style = GetWindowLong(hWnd, GWL_EXSTYLE);
	style &= ~(WS_EX_APPWINDOW);
	ShowWindow(hWnd, SW_HIDE);
	SetWindowLong(hWnd, GWL_EXSTYLE, style | WS_EX_TOOLWINDOW);
	ShowWindow(hWnd, SW_SHOW);
}

void WindowUtils::taskbar_show(int64_t hwnd){
	if (!hwnd) return;
	HWND hWnd = (HWND)(LONG_PTR)hwnd;
	LONG style = GetWindowLong(hWnd, GWL_EXSTYLE);
	ShowWindow(hWnd, SW_HIDE);
	SetWindowLong(hWnd, GWL_EXSTYLE, style & ~WS_EX_TOOLWINDOW);
	ShowWindow(hWnd, SW_SHOW);
}