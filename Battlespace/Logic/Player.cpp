
#include <iostream>
#include "../Headers/Player.h"

unsigned Player::players = 0;

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

    this->player_num = Player::players;
    Player::players++;
    std::cout << this->player_num << std::endl;
}

Player::~Player()
{

}

void Player::draw(RenderTarget &target)
{
    target.draw(this->sprite);

    for (size_t i = 0; i < this->bullets.size(); i++)
    {
        this->bullets[i].draw(target);
    }
}

void Player::update(Vector2u window_bound)
{
    this->move_up();
    this->move_down();
    this->shoot();

    // update timers
    if (this->shoot_timer < this->shoot_timer_max) this->shoot_timer++;
    if (this->damage_timer < this->damage_timer_max) this->damage_timer++;

}

void Player::move_up()
{
    if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::up] = up)))
        this->sprite.move(0.f, -10.f);
}

void Player::move_down()
{
    if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::down] = down)))
        this->sprite.move(0.f, 10.f);
}

void Player::shoot()
{
    if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::shootx] = shootx)) && this->shoot_timer >= shoot_timer_max)
    {
        this->bullets.push_back(Bullet(bullet, this->sprite.getPosition()));

        // reset timer
        this->shoot_timer = 0;
    }
}