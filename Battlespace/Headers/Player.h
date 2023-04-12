
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

    Player();
    virtual ~Player();

    void draw();
    void update();

private:

    Sprite shape;
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
};

#endif //BATTLESPACE_PLAYER_H
