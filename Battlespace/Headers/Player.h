
#ifndef BATTLESPACE_PLAYER_H
#define BATTLESPACE_PLAYER_H

#include "../Headers/Bullet.h"

class Player
{
public:

    Player(Texture *texture, Texture *bullet, int up = 73, int down = 74, int shoot = 58);
    virtual ~Player();

    void draw(RenderTarget &target);
    void update(Vector2u window_bounds, RenderTarget &target, int);

    void move_up(RenderTarget &target, int);
    void move_down(RenderTarget &target, int);
    Bullet * shoot(RenderTarget &target);

    static unsigned players;

    // Accessors
    inline std::vector<Bullet>& getBullets(){return this->bullets;}

private:

    Sprite sprite;
    RectangleShape hit_box;
    Texture *texture;

    int level;
    int exp;
    int exp_next;

    int hp;
    int hp_max;

    int score;

    int damage;
    int damage_max;

    int controls[3];

    unsigned player_num;

    Bullet *bulletp;
    Texture *bullet;
    std::vector<Bullet> bullets;

    int shoot_timer;
    int shoot_timer_max;
    int damage_timer;
    int damage_timer_max;
};

#endif //BATTLESPACE_PLAYER_H
