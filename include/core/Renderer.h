#pragma once

class Renderer {
public:
	Renderer();
	bool initialize();
	void shutdown();
	void renderFrame();
};