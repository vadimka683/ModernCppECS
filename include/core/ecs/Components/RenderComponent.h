#pragma once

struct RenderComponent {
	char symbol = '?';
	RenderComponent() = default;
	~RenderComponent() = default;
	RenderComponent(char symbol): symbol(symbol){}
	RenderComponent(const RenderComponent& other) = default;
	RenderComponent& operator=(const RenderComponent& other) = default;
};

namespace std {
	template<>
	void swap<RenderComponent>(RenderComponent& a, RenderComponent& b)noexcept {
		using std::swap;
		swap(a.symbol, b.symbol);
	}
}