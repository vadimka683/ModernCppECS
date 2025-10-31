#include "core/Window.h"

Window::Window() {}
Window::~Window() {}
bool Window::create() {
	return true;
}
void Window::destroy() {}
bool Window::shouldClose() {
	return false;
}