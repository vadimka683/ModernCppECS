#pragma once
#include<type_traits>
#include "EntityManager.h"

template<typename Component>
class ComponentTraits {
	static constexpr bool is_registered = false;
	static constexpr char* name = "Unknown";

	static auto& getStorage(EntityManager& em);
	static auto& getMap(EntityManager& em);
	static const auto& getStorage(const EntityManager& em);
	static const auto& getMap(const EntityManager& em);
};