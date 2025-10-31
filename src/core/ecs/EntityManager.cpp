#include "core/ecs/EntityManager.h"
#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
#include "core/ecs/Components/TransformComponent.h"
#include "core/ecs/Components/RenderComponent.h"
#include "core/ecs/Components/HealthComponent.h"

Entity EntityManager::createEntity() {
	Entity newEntity;
	if (availableEntities.empty()) {
		newEntity = nextEntityId++;
		return newEntity;
	}
	newEntity = availableEntities[0];
	std::swap(availableEntities[0], availableEntities.back());
	availableEntities.pop_back();
	return newEntity;
}

void EntityManager::destroyEntity(Entity entity) {}
void EntityManager::addTransformComponent(Entity entity, TransformComponent&& component) {
	std::unordered_map<Entity,size_t>::iterator it = TransformComponentsMap.find(entity); 	// auto it = TransformComponentsMap.find(entity);
	if (it == TransformComponentsMap.end()) {
		TransformComponents.push_back(std::move(component));
		size_t numberInVTransforms = TransformComponents.size() - 1;
		TransformComponentsMap.emplace(entity, numberInVTransforms);
		return;
	}
	std::cout << "Warning: TransformComponent already exists for entity " << entity << "\n";
}
void EntityManager::addRenderComponent(Entity entity, RenderComponent&& component) {
	auto it = RenderComponentsMap.find(entity);
	if (it == RenderComponentsMap.end()) {
		RenderComponents.push_back(std::move(component));
		RenderComponentsMap.emplace(entity, RenderComponents.size() - 1);
		return;
	}
	std::cout << "Warning: RenderComponent already exists for entity " << entity << "\n";
}
void EntityManager::addHealthComponent(Entity entity, HealthComponent&& component) {
	auto it = HealthComponentsMap.find(entity);
	if (it == HealthComponentsMap.end()) {
		HealthComponents.push_back(std::move(component));
		HealthComponentsMap.emplace(entity, HealthComponents.size() - 1);
		return;
	}
	std::cout << "Warning: HealthComponent already exists for entity " << entity << "\n";
}
void EntityManager::removeTransformComponent(Entity entity) {
	std::unordered_map<Entity, size_t>::iterator it = TransformComponentsMap.find(entity);
	if (it == TransformComponentsMap.end()) {
		std::cout << "Warning: TransformComponent is not exist\n";
		return;
	}
	std::swap(TransformComponents[it->second], TransformComponents.back());
	TransformComponents.pop_back();
	TransformComponentsMap.erase(entity);
}
void EntityManager::removeRenderComponent(Entity entity) {
	auto it = RenderComponentsMap.find(entity);
	if (it == TransformComponentsMap.end()) {
		std::cout << "Warning: RenderComponent is not exist\n";
		return;
	}
	std::swap(RenderComponents[it->second], RenderComponents.back());
	RenderComponents.pop_back();
	RenderComponentsMap.erase(entity);
}
void EntityManager::removeHealthComponent(Entity entity) {
	auto it = HealthComponentsMap.find(entity);
	if (it == HealthComponentsMap.end()) {
		std::cout << "Warning: RenderComponent is not exist\n";
		return;
	}
	std::swap(HealthComponents[it->second], HealthComponents.back());
	HealthComponents.pop_back();
	HealthComponentsMap.erase(entity);
}

TransformComponent* EntityManager::getTransformComponent(Entity entity) {
	auto it = TransformComponentsMap.find(entity);
	if (it == TransformComponentsMap.end()) {
		std::cout << "Warning: TransformComponent is not exist\n";
		return nullptr;
	}
	return &TransformComponents[it->second];
}
RenderComponent* EntityManager::getRenderComponent(Entity entity){
	auto it = RenderComponentsMap.find(entity);
	if (it == RenderComponentsMap.end()) {
		std::cout << "Warning: RenderComponent is not exist\n";
		return nullptr;
	}
	return &RenderComponents[it->second];
}
HealthComponent* EntityManager::getHealthComponent(Entity entity) {
	auto it = HealthComponentsMap.find(entity);
	if (it == HealthComponentsMap.end()) {
		std::cout << "Warning: HealthComponent is not exist\n";
		return nullptr;
	}
	return &HealthComponents[it->second];
}
