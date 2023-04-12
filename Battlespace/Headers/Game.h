
#ifndef BATTLESPACE_GAME_H
#define BATTLESPACE_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Audio.hpp>

using namespace sf;

#pragma once
class Game
{
public:

    Game(RenderWindow *window);
    virtual ~Game();

    void update();
    void draw();

    // Accesors
    inline RenderWindow& getWindow() {return *this->window;}

    // Setters

private:

    RenderWindow *window;
};

#endif //BATTLESPACE_GAME_H
