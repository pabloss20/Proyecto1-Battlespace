
#ifndef BATTLESPACE_GAME_H
#define BATTLESPACE_GAME_H

// Classes
#include "../Headers/Player.h"

using namespace sf;

class Game
{
public:

    Game(RenderWindow *window);
    virtual ~Game();

    void update();
    void draw();
    void combat_update();

    // Accesors
    inline RenderWindow& getWindow() {return *this->window;}

    // Setters

private:

    RenderWindow *window;
    Player *player;
    Texture player_texture;
    Texture bullet_texture;
};

#endif //BATTLESPACE_GAME_H
