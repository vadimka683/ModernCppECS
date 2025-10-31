#pragma once

struct TransformComponent {
	float x = 0.0f;
	float y = 0.0f;
	float speed = 0.0f;
	TransformComponent() = default;
	~TransformComponent() = default;
	TransformComponent(const TransformComponent& other) : x(other.x), y(other.y), speed(other.speed) {}
	TransformComponent(float x, float y, float speed = 0.0f) : x(x), y(y), speed(speed) {}
};

namespace std {
	template<>
	void swap<TransformComponent>(TransformComponent& a, TransformComponent& b) noexcept {
		using std::swap;
		swap(a.x, b.x);
		swap(a.y, b.y);
		swap(a.speed, b.speed);
	}
}
