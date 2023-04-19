
#ifndef PROYECTO1_A_D2_LISTA_H
#define PROYECTO1_A_D2_LISTA_H

#include "Bullet.h"

class BulletSPawner {

    Bullet *head;

public:

    // Constructor
    BulletSPawner() {head = NULL;}

    void create_bullet(int);
    void insert_bullet(Texture *texture, int, int);
    void delete_bullet(int);
    void print_bullet_list();
    void spawn_bullets(RenderTarget &target);
    void move_bullets(RenderWindow *window);

    void update(Vector2u window_bounds);

private:

    Texture bullet_texture;
};


#endif //PROYECTO1_A_D2_LISTA_H
