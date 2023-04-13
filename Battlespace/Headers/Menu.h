
#ifndef BATTLESPACE_MENU_H
#define BATTLESPACE_MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define max_menu 4

class Menu
{
public:

    Menu(float width, float height);
    ~Menu();

    void draw(RenderWindow& window);
    void move_up();
    void move_down();

    int menu_pressed(){ return menu_selected; }

private:

    int menu_selected;
    Font font;
    Text menu[max_menu];
};

#endif //BATTLESPACE_MENU_H
