
#include "../Headers/EnemySpawner.h"

void EnemySpawner::create_enemy(int limit)
{
    // Set value
    srand((unsigned) time(NULL));

    enemy_texture.loadFromFile("../Assets/enemy.png");

    int xpos = 1475, ypos, health = 100, idm;

    for (int i = 1; i < limit; i++)
    {
        // get random number 0 or 1
        idm = 0 + (rand() % 2);
        // get random y position
        ypos = 0 + (rand() % 900);

        this->insert_enemy(&this->enemy_texture, i, xpos, ypos, health, idm);
    }
}