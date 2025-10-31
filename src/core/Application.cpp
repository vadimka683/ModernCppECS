#include "core/Application.h"
#include "core/Window.h"
#include "core/InputManager.h"
#include "core/Renderer.h"
#include<iostream>
#include<memory>
#include<chrono>

Application::~Application() = default;
Application::Application(): m_window(nullptr), m_inputManager(nullptr),
						m_renderer(nullptr), m_running(false) {}

bool Application::initialize() {
	m_window = std::make_unique<Window>();
	m_renderer = std::make_unique<Renderer>();
	m_inputManager = std::make_unique<InputManager>();

	if (m_window->create()) {
		std::cout << "Window created\n";
	}
	else { return false; }
	if (m_renderer->initialize()) {
		std::cout << "Rendering is start\n";
	}
	else { return false; }
	this->m_running = true;
	std::cout << "m_running if true\n";
	return true;
}
void Application::update(float deltaTime) {
	std::cout << "Logic is updated\n";
}
void Application::render() {
	m_renderer->renderFrame();
}
void Application::processInput() {
	m_inputManager->update();
}
void Application::run() {
	int CountFrame = 0;
	auto lastFrame = std::chrono::steady_clock::now();
	while (m_running && !m_window->shouldClose()) {
		this->processInput();

		auto newFrame = std::chrono::steady_clock::now();
		auto dur = newFrame - lastFrame;
		float deltaTime = std::chrono::duration<float>(dur).count();
		lastFrame = newFrame;

		this->update(deltaTime);
		this->render();
		CountFrame++;
		if (CountFrame == 5) {
			return;
		}
	}
	std::cout << "HELLO Word";
}
void Application::shutdown() {
	m_running = false;
	std::cout << "Stoped";
}