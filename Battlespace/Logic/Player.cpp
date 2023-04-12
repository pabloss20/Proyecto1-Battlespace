
#include <iostream>
#include "../Headers/Player.h"

unsigned Player::players = 0;

enum controls {up = 73, down = 74, shoot = 58};

Player::Player(Texture *texture, int up, int down, int shoot)

        :level(1), exp(0), exp_next(100),
         hp(5), hp_max(5), damage(1),
         damage_max(2), score(0)
{
    this->texture = texture;
    this->sprite.setTexture(*this->texture);

    this->controls[controls::up] = up;
    this->controls[controls::down] = down;
    this->controls[controls::shoot] = shoot;

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
}

void Player::update()
{
    this->move_up();
}

void Player::move_up()
{
    if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::up] = up)))
        this->sprite.move(0.f, -10.f);
    if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::down] = down)))
        this->sprite.move(0.f, 10.f);
    if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[controls::shoot] = shoot)))
    {}
}

void Player::move_down()
{

}