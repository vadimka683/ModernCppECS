#include "core/Renderer.h"
#include<iostream>

Renderer::Renderer(){}
bool Renderer::initialize() {
	return true;
}
void Renderer::shutdown(){}
void Renderer::renderFrame() {
	std::cout << "Rendering frame...\n";
}