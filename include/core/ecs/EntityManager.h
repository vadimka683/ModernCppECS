#pragma once
#include<vector>
#include<memory>
#include<unordered_map>
#include "Entity.h"
struct TransformComponent;
struct RenderComponent;
struct VelocityComponent;
class HealthComponent;
struct MoveIntentComponent;

enum class RemoveMode {
	WithWarning,
	Silent
};

class EntityManager {
public:
	Entity nextEntityId = 1;
		std::vector<Entity> availableEntities = {};
	std::vector<TransformComponent> TransformComponents;
	std::vector<VelocityComponent> VelocityComponents;
	std::vector<MoveIntentComponent> MoveIntentComponents;
	std::vector<RenderComponent> RenderComponents;
	std::vector<HealthComponent> HealthComponents;

	std::unordered_map<Entity, size_t> TransformComponentsMap;
	std::unordered_map<Entity, size_t> VelocityComponentsMap;
	std::unordered_map<Entity, size_t> MoveIntentComponentsMap;
	std::unordered_map<Entity, size_t> RenderComponentsMap;
	std::unordered_map<Entity, size_t> HealthComponentsMap;
	EntityManager() = default;
	EntityManager(const EntityManager& other) = default;
	Entity createEntity();
	void destroyEntity(Entity entity);

	// Template func
	template<typename Component>
	bool hasComponent(Entity entity);

	template<typename Component>
	bool hasComponent(Entity entity) const;

	void addTransformComponent(Entity entity, TransformComponent&& component);
	void removeTransformComponent(Entity entity, RemoveMode mode = RemoveMode::WithWarning);
	TransformComponent* getTransformComponent(Entity entity);

	void addVelocityComponent(Entity entity, VelocityComponent&& component);
	void removeVelocityComponent(Entity entity, RemoveMode mode = RemoveMode::WithWarning);
	VelocityComponent* getVelocityComponent(Entity entity);

	void addMoveIntentComponent(Entity entity, MoveIntentComponent&& component);
	void removeMoveIntentComponent(Entity entity, RemoveMode = RemoveMode::WithWarning);
	MoveIntentComponent* getMoveIntentComponent(Entity entity);

	void addRenderComponent(Entity entity, RenderComponent&& component);
	void removeRenderComponent(Entity entity, RemoveMode mode = RemoveMode::WithWarning);
	RenderComponent* getRenderComponent(Entity entity);

	void addHealthComponent(Entity entity, HealthComponent&& component);
	void removeHealthComponent(Entity entity, RemoveMode mode = RemoveMode::WithWarning);
	HealthComponent* getHealthComponent(Entity entity);
};