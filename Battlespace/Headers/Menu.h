
#ifndef BATTLESPACE_MENU_H
#define BATTLESPACE_MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Menu
{
public:

    Menu(float width, float height);
    ~Menu();

    void draw(RenderWindow& window);
    void move_up();
    void move_down();

    void setSelected(int option);
    int menu_pressed(){ return option; }

    Text options[4];

private:

    int option;
    Font font;
};

#endif //BATTLESPACE_MENU_H
