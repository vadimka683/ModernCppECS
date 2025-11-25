#pragma once
#include <utility>

class HealthComponent {
private:
	int currentHealth = 100;
	int maxHealth = 100;
	bool isALive = true;
public:
	HealthComponent() = default;
	~HealthComponent() = default;
	HealthComponent(int currentHealth, int MaxHealth);
	HealthComponent(const HealthComponent& other);
	void takeDamage(int damage);
	void heal(int countHeal);
	friend void swap(HealthComponent& a, HealthComponent& b) noexcept {
		using std::swap;
		swap(a.currentHealth, b.currentHealth);
		swap(a.maxHealth, b.maxHealth);
		swap(a.isALive, b.isALive);
	}
};