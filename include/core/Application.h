#pragma once 
#include<iostream>
#include<memory>

class Window;
class Renderer;
class InputManager;

class  Application {
private:
	std::unique_ptr<Window> m_window;
	std::unique_ptr<Renderer> m_renderer;
	std::unique_ptr<InputManager> m_inputManager;
	bool m_running;
	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;
	void update(float deltaTime);
	void render();
	void processInput();
public:
	~Application();
	Application();
	bool initialize();
	void run();
	void shutdown();
};