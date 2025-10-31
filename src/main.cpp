#include "core/Application.h"
#include<memory>

int main() {
	auto testRun = std::make_unique<Application>();
	testRun->initialize();
	testRun->run();
	testRun->shutdown();
}