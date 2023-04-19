
#ifndef BATTLESPACE_ENEMYSPAWNER_H
#define BATTLESPACE_ENEMYSPAWNER_H

#include "Enemy.h"

class EnemySpawner
{
    Enemy *head;

public:

    // Constructor
    EnemySpawner() {head = NULL;}

    void create_enemy(int);
    void insert_enemy(Texture *texture, int, int, int, int, int);
    void delete_enemy(int);
    Enemy * print_enemy_list();
    void spawn_enemies(RenderTarget &target);
    void move_enemies(RenderWindow *window);

    void update(Vector2u window_bounds);

    int size;
    void setSize(int);
    int getSize();

private:

    Texture enemy_texture;
};

#endif //BATTLESPACE_ENEMYSPAWNER_H
