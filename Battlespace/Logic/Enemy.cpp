
#include "../Headers/Enemy.h"

Enemy::Enemy(Texture *texture, int id, int x_pos, int y_pos, int health, int movement)
{
    this->texture = texture;
    this->id = id;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->health = health;
    this->movement = movement;
    this->next = NULL;

    this->sprite.setTexture(*this->texture);
}