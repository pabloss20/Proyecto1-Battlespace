
#ifndef BATTLESPACE_GAME_H
#define BATTLESPACE_GAME_H

// Classes
#include "../Headers/Player.h"

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
    Player *player;
    Player *player2;
    Texture player_texture;
};

#endif //BATTLESPACE_GAME_H
