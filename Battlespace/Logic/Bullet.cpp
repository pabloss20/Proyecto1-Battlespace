
#include "../Headers/Bullet.h"

Bullet::Bullet(Texture *texture, Vector2f position, Vector2f max_velocity)
{
    this->texture = texture;
    this->sprite.setTexture(*this->texture);
    this->max_velocity = max_velocity;

    this->sprite.setPosition(position);
}

Bullet::~Bullet()
{

}

void Bullet::update()
{
    this->move();
}

void Bullet::draw(RenderTarget &target)
{
    target.draw(this->sprite);
}


void Bullet::move()
{
    this->sprite.move(this->max_velocity.x, this->max_velocity.y);
}