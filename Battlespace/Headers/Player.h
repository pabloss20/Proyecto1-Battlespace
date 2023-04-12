
#ifndef BATTLESPACE_PLAYER_H
#define BATTLESPACE_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Audio.hpp>

using namespace sf;

class Player
{
public:

    Player(Texture *texture, int up = 73, int down = 74, int shoot = 58);
    virtual ~Player();

    void draw(RenderTarget &target);
    void update();

    void move_up();
    void move_down();

    static unsigned players;

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
};

#endif //BATTLESPACE_PLAYER_H
