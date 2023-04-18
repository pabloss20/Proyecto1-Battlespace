cmake_minimum_required(VERSION 3.24)
project(Battlespace)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio)

add_executable(Battlespace main.cpp Headers/Game.h Logic/Game.cpp Headers/Player.h Logic/Player.cpp Headers/Bullet.h Logic/Bullet.cpp Headers/Enemy.h Logic/Enemy.cpp Headers/EnemySpawner.h Logic/EnemySpawner.cpp Logic/arduinoHndlr.cpp Headers/Lista.h Headers/Bnode.h Headers/BList.h Headers/Bcollector.h Logic/Bcollector.cpp Logic/BList.cpp Logic/Bnode.cpp Logic/Lista.cpp libserial/SerialPort.cpp libserial/SerialPort.h libserial/SerialPortConstants.h libserial/SerialStream.cpp libserial/SerialStreamBuf.cpp libserial/SerialStreamBuf.h libserial/SerialStreamBuf.h libserial/SerialStreamBuf.h libserial/SerialStreamBuf.cpp libserial/SerialStream.cpp libserial/SerialPort.h libserial/SerialPort.cpp libserial/SerialPort.cpp libserial/SerialPort.h libserial/SerialStream.cpp libserial/SerialStreamBuf.cpp libserial/SerialPort.cpp)

target_link_libraries(Battlespace sfml-graphics sfml-audio)