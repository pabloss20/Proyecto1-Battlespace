
#ifndef BATTLESPACE_ENEMY_H
#define BATTLESPACE_ENEMY_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;

class Enemy
{
public:

    // Constructor
    Enemy(){id = 0; next = NULL;}

    // Parametized constructor
    Enemy(Texture *texture, int id, int x_pos, int y_pos, int health, int movement);

    int id;
    int x_pos;
    int y_pos;
    int health;
    int movement;

    Enemy *next;

    void draw(RenderTarget &target);
    void update(Vector2u window_bounds);
    void move(int, RenderWindow *window);
    void setXpos(int);
    int getXpos();
    void setYpos(int);
    int getYpos();
    void setHealth(int);
    int getHealth();


private:

    Texture *texture;
    RectangleShape hit_box;
    Sprite sprite;

};

#endif //BATTLESPACE_ENEMY_H
