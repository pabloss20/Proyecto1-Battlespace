
#include <iostream>
#include "../Headers/Player.h"

enum controls {up = 73, down = 74, shootx = 58};

Player::Player(Texture *texture, Texture *bullet, int up, int down, int shootx)

        :level(1), exp(0), exp_next(100),
         hp(5), hp_max(5), damage(1),
         damage_max(2), score(0)
{
    this->texture = texture;
    this->bullet = bullet;
    this->sprite.setTexture(*this->texture);

    this->controls[controls::up] = up;
    this->controls[controls::down] = down;
    this->controls[controls::shootx] = shootx;

    this->shoot_timer_max = 15;
    this->shoot_timer = this->shoot_timer_max;

    this->damage_timer_max = 10;
    this->damage_timer = this->damage_timer_max;

}

Player::~Player()
{

}

void Player::draw(RenderTarget &target)
{
    target.draw(this->sprite);
}

void Player::update(Vector2u window_bound, RenderTarget &target, int num)
{
    this->move_up(target, num);
    this->move_down(target, num);

    // update timers
    if (this->shoot_timer < this->shoot_timer_max) this->shoot_timer++;
    if (this->damage_timer < this->damage_timer_max) this->damage_timer++;
}

void Player::move_up(RenderTarget &target, int num)
{
    if (num == 1)this->sprite.move(0.f, -20.f);
    //this->shoot(target);
}

void Player::move_down(RenderTarget &target, int num)
{
    if (num == 2){this->sprite.move(0.f, 20.f);}
    //this->shoot(target);
}

Bullet * Player::shoot(RenderTarget &)
{
    if (this->shoot_timer >= shoot_timer_max)
    {
        std::cout << "wk";
        bulletp = new Bullet(bullet, this->sprite.getPosition());

        this->shoot_timer = 0;
    }

    return bulletp;
}