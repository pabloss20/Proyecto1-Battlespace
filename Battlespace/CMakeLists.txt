cmake_minimum_required(VERSION 3.24)
project(Battlespace)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio)

add_executable(Battlespace main.cpp Headers/Game.h Logic/Game.cpp Headers/Player.h Logic/Player.cpp Headers/Bullet.h Logic/Bullet.cpp Headers/Menu.h Logic/Menu.cpp Headers/Enemy.h Logic/Enemy.cpp Headers/EnemySpawner.h Logic/EnemySpawner.cpp)

target_link_libraries(Battlespace sfml-graphics sfml-audio)