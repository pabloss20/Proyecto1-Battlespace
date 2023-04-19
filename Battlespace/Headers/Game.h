
#ifndef BATTLESPACE_GAME_H
#define BATTLESPACE_GAME_H

// Classes
#include "../Headers/Player.h"
#include "EnemySpawner.h"

using namespace sf;

class Game
{
public:

    Game();

    void start();
    void update(RenderWindow *window, int);
    void draw(RenderWindow *window);
    void combat_update();

private:

    EnemySpawner *enemySpawner;
    Enemy *enemy;
    Bullet *bullet;
    Player *player;
    Texture player_texture;
    Texture bullet_texture;
};

#endif //BATTLESPACE_GAME_H
