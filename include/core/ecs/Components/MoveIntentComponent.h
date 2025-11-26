#pragma once

struct MoveIntentComponent
{
public:
	float moveX = 0.0f;
	float moveY = 0.0f;
	MoveIntentComponent() = default;
	MoveIntentComponent(const MoveIntentComponent& other) = default;
	MoveIntentComponent& operator=(const MoveIntentComponent& other) = default;
};

namespace std {
	template<>
	void swap<MoveIntentComponent>(MoveIntentComponent& a, MoveIntentComponent& b) noexcept {
		std::swap(a.moveX, b.moveX);
		std::swap(a.moveY, b.moveY);
	}
}