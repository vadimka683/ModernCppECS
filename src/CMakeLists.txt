# Все файлы в src/core/
add_executable(RogalicPure 
    main.cpp
    core/Application.cpp
    core/InputManager.cpp
    core/Renderer.cpp
    core/Window.cpp
    core/ecs/Component.cpp
    core/ecs/EntityManager.cpp
    core/ecs/System.cpp
    core/ecs/Components/HealthComponent.cpp
    core/ecs/Systems/CombatSystem.cpp
    core/ecs/Systems/MovementSystem.cpp)

# Include папка на уровень выше
target_include_directories(RogalicPure PUBLIC ${CMAKE_SOURCE_DIR}/include)