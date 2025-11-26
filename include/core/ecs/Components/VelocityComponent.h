#pragma once

struct VelocityComponent {
	float dx = 0.0f;
	float dy = 0.0f;
	
	VelocityComponent() = default;
	VelocityComponent(float dx, float dy): dx(dx), dy(dy){}
	VelocityComponent(const VelocityComponent& other) = default;
	VelocityComponent& operator=(const VelocityComponent& other) = default;
};

namespace std {
	template<>
	void swap<VelocityComponent>(VelocityComponent& a, VelocityComponent& b) {
		using std::swap;
		swap(a.dx, b.dx);
		swap(a.dy, b.dy);
	}
}