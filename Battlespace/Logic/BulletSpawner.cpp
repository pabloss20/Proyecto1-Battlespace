
#include <iostream>
#include "../Headers/BulletSPawner.h"

void BulletSPawner::create_bullet(int limit)
{
    bullet_texture.loadFromFile("../Assets/bullet.png");

    // Set value
    srand((unsigned) time(NULL));

    int health = 100;

    for (int i = 1; i < limit; i++)
    {
        this->insert_bullet(&this->bullet_texture, i, health);
    }
}

void BulletSPawner::insert_bullet(Texture *texture, int data, int damage) {

    Bullet *bullet = new Bullet();

    if (head == NULL){head = bullet; return;}

    Bullet *aux = head;

    while (aux->next != NULL){aux = aux->next;}

    aux->next = bullet;
}

void BulletSPawner::print_bullet_list()
{
    Bullet* aux = head;

    // Check for empty list.
    if (head == NULL) {std::cout << "List empty" << std::endl; return;}

    // Traverse the list.
    while (aux != NULL)
    {
        std::cout << aux->id << " ";
        std::cout << aux->damage << " ";
        std::cout << aux << "\n";

        aux = aux->next;
    }
}

void BulletSPawner::spawn_bullets(RenderTarget &target)
{
    Bullet* aux = head;

    // Check for empty list.
    if (head == NULL) {std::cout << "List empty" << std::endl; return;}

    // Traverse the list.
    while (aux != NULL)
    {
        aux->draw(target);
        aux = aux->next;
    }
}
