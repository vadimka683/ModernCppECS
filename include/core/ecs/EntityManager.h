#pragma once
#include<vector>
#include<memory>
#include<unordered_map>
#include "Entity.h"
struct TransformComponent;
struct RenderComponent;
class HealthComponent;

enum class RemoveMode {
	WithWarning,
	Silent
};

class EntityManager {
private:
	Entity nextEntityId = 1;
	std::vector<Entity> availableEntities = {};
	std::vector<TransformComponent> TransformComponents;
	std::vector<RenderComponent> RenderComponents;
	std::vector<HealthComponent> HealthComponents;

	std::unordered_map<Entity, size_t> TransformComponentsMap;
	std::unordered_map<Entity, size_t> RenderComponentsMap;
	std::unordered_map<Entity, size_t> HealthComponentsMap;
public:
	EntityManager() = default;
	EntityManager(const EntityManager& other) = default;
	Entity createEntity();
	void destroyEntity(Entity entity);

	void addTransformComponent(Entity entity, TransformComponent&& component);
	void removeTransformComponent(Entity entity, RemoveMode mode = RemoveMode::WithWarning);
	TransformComponent* getTransformComponent(Entity entity);

	void addRenderComponent(Entity entity, RenderComponent&& component);
	void removeRenderComponent(Entity entity, RemoveMode mode = RemoveMode::WithWarning);
	RenderComponent* getRenderComponent(Entity entity);

	void addHealthComponent(Entity entity, HealthComponent&& component);
	void removeHealthComponent(Entity entity, RemoveMode mode = RemoveMode::WithWarning);
	HealthComponent* getHealthComponent(Entity entity);
};