
#include "../Headers/Menu.h"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("../Assets/font.otf")) cout << "NO FONT IS HERE";

    // Easy
    menu[0].setFont(font);
    menu[0].setFillColor(Color::White);
    menu[0].setString("Easy");
    menu[0].setCharacterSize(60);
    menu[0].setPosition(700, 400);

    // Normal
    menu[1].setFont(font);
    menu[1].setFillColor(Color::White);
    menu[1].setString("Normal");
    menu[1].setCharacterSize(60);
    menu[1].setPosition(700, 500);

    // Expert
    menu[2].setFont(font);
    menu[2].setFillColor(Color::White);
    menu[2].setString("Expert");
    menu[2].setCharacterSize(60);
    menu[2].setPosition(700, 600);

    //Quit
    menu[3].setFont(font);
    menu[3].setFillColor(Color::White);
    menu[3].setString("Quit");
    menu[3].setCharacterSize(60);
    menu[3].setPosition(700, 700);

    menu_selected = -1;
}

// Drawing menu
void Menu::draw(RenderWindow &window)
{
    for (size_t i = 0; i < max_menu; ++i) {window.draw(menu[i]);}
}

void Menu::move_up()
{
    if (menu_selected - 1 >= 0)
    {
        menu[menu_selected].setFillColor(Color::White);

        menu_selected--;

        if (menu_selected == -1) { menu_selected = 2; }

        menu[menu_selected].setFillColor(Color::Yellow);
    }
}

void Menu::move_down()
{
    if (menu_selected + 1 < max_menu)
    {
        menu[menu_selected].setFillColor(Color::White);

        menu_selected++;

        if (menu_selected == -1) {menu_selected = 4;}

        menu[menu_selected].setFillColor(Color::Yellow);
    }
}