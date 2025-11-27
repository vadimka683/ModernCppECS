#pragma once
#include "ComponentTraits.h"

template<>
struct ComponentTraits<HealthComponent> {
	static constexpr bool is_registered = true;
	static constexpr const char* name = "HealthComponent";
	static auto& getStorage(EntityManager& em) { return em.HealthComponents; }
	static auto& getMap(EntityManager& em) { return em.HealthComponentsMap; }
	static const auto& getStorage(const EntityManager& em) { return em.HealthComponents; }
	static const auto& getMap(const EntityManager& em) { return em.HealthComponentsMap; }
};

template<>
struct ComponentTraits<MoveIntentComponent> {
	static constexpr bool is_registered = true;
	static constexpr const char* name = "MoveIntentComponent";
	static auto& getStorage(EntityManager& em) { return em.MoveIntentComponents; }
	static auto& getMap(EntityManager& em) { return em.MoveIntentComponentsMap; }
	static const auto& getStorage(const EntityManager& em) { return em.MoveIntentComponents; }
	static const auto& getMap(const EntityManager& em) { return em.MoveIntentComponentsMap; }

};

template<>
struct ComponentTraits<RenderComponent> {
	static constexpr bool is_registered = true;
	static constexpr const char* name = "RenderComponent";
	static auto& getStorage(EntityManager& em) { return em.RenderComponents; }
	static auto& getMap(EntityManager& em) { return em.RenderComponentsMap; }
	static const auto& getStorage(const EntityManager& em) { return em.RenderComponents; }
	static const auto& getMap(const EntityManager& em) { return em.RenderComponentsMap; }
};

template<>
struct ComponentTraits<TransformComponent> {
	static constexpr bool is_registered = true;
	static constexpr const char* name = "TransformComponent";
	static auto& getStorage(EntityManager& em) { return em.TransformComponents; }
	static auto& getMap(EntityManager& em) { return em.TransformComponentsMap; }
	static const auto& getStorage(const EntityManager& em) { return em.TransformComponents; }
	static const auto& getMap(const EntityManager& em) { return em.TransformComponentsMap; }
};

template<>
struct ComponentTraits<VelocityComponent> {
	static constexpr bool is_registered = true;
	static constexpr const char* name = "VelocityComponent";
	static auto& getStorage(EntityManager& em) { return em.VelocityComponents; }
	static auto& getMap(EntityManager& em) { return em.VelocityComponentsMap; }
	static const auto& getStorage(const EntityManager& em) { return em.VelocityComponents; }
	static const auto& getMap(const EntityManager& em) { return em.VelocityComponentsMap; }
};