
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


void Enemy::draw(RenderTarget &target)
{
    this->sprite.setPosition(this->x_pos, this->y_pos);
    target.draw(this->sprite);
}

void Enemy::update(Vector2u window_bound){}

void Enemy::move(int idm, RenderWindow *window)
{
    switch (idm)
    {
        case 0:

            while (this->getXpos() > -10)
            {
                this->sprite.move(-3.f, 0.f);
                this->setXpos(this->getXpos() - 10.f);
            }
            break;

        case 1:

            while (this->getXpos() > -10)
            {
                while (this->getYpos() > 0)
                {
                    if (this->getYpos() == 0)
                    {
                        while (this->getYpos() < 901)
                        {
                            this->sprite.move(-3.f, 3.f);
                            this->setYpos(this->getYpos() + 3.f);
                        }
                    }
                    this->sprite.move(-3.f, -3.f);
                    this->setYpos(this->getYpos() - 3.f);
                }
                this->setXpos(this->getXpos() - 10);
            }
            break;
    }
}

void Enemy::setXpos(int pos)
{
    this->x_pos = pos;
}

int Enemy::getXpos()
{
    return this->x_pos;
}

void Enemy::setYpos(int pos)
{
    this->y_pos = pos;
}

int Enemy::getYpos()
{
    return this->y_pos;
}

void Enemy::setHealth(int healthx) {
    this->health = healthx;
}

int Enemy::getHealth() {
    return this->health;
}