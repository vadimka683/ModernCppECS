#include "core/ecs/Components/HealthComponent.h"
#include<algorithm>
#include<iostream>

HealthComponent::HealthComponent(int currentHealth, int maxHealth){
	this->maxHealth = std::max(1, maxHealth);
	this->currentHealth = std::clamp(currentHealth, 0, this->maxHealth);
	if (this->currentHealth > 0) { isALive = true; }
	else { isALive = false; }
	if (currentHealth > maxHealth){
		std::cout << "Warning: currentHealth > MaxHealth\n";
	}
	else if (maxHealth <= 0) {
		std::cout << "Warning: MaxHealth < 0\n";
	}
}
HealthComponent::HealthComponent(const HealthComponent& other) = default;
void HealthComponent::takeDamage(int damage) {
	if (damage <= 0) {
		std::cout << "Warning: damage <= 0\n";
		return;
	}
	currentHealth -= damage;
	currentHealth = std::max(0, currentHealth);
	if (currentHealth == 0) { isALive = false; }
}
void HealthComponent::heal(int countHeal) {
	if (countHeal <= 0) {
		std::cout << "Warning: heal <= 0\n";
		return;
	}
	currentHealth += countHeal;
	currentHealth = std::min(maxHealth, currentHealth);
	if (currentHealth > 0) {
		isALive = true;
	}
}