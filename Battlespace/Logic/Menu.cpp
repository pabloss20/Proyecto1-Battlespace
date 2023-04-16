
#include "../Headers/Menu.h"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("../Assets/font.otf")) cout << "NO FONT IS HERE";

    // Easy
    options[0].setFont(font);
    options[0].setFillColor(Color::White);
    options[0].setString("Easy");
    options[0].setCharacterSize(60);
    options[0].setPosition(Vector2f(width / 2, height / (4)));

    // Normal
    options[1].setFont(font);
    options[1].setFillColor(Color::White);
    options[1].setString("Normal");
    options[1].setCharacterSize(60);
    options[1].setPosition(Vector2f(width / 2, height / (4) + 200));

    // Expert
    options[2].setFont(font);
    options[2].setFillColor(Color::White);
    options[2].setString("Expert");
    options[2].setCharacterSize(60);
    options[2].setPosition(Vector2f(width / 2, height / (4) + 400));

    //Quit
    options[3].setFont(font);
    options[3].setFillColor(Color::White);
    options[3].setString("Quit");
    options[3].setCharacterSize(60);
    options[3].setPosition(Vector2f(width / 2, height / (4) + 600));

    option = 0;
}

Menu::~Menu() {}

void Menu::setSelected(int optionx) {option = optionx;}

// Drawing options
void Menu::draw(RenderWindow &window)
{
    for (int i = 0; i < 4; ++i) {window.draw(options[i]);}
}

void Menu::move_up()
{
    if (option - 1 >= -1) {
        options[option].setFillColor(Color::White);
        option--;

        if (option == -1) { option = 3; }

        options[option].setFillColor(Color::Yellow);
    }
}

void Menu::move_down()
{
    if (option + 1 <= 4){ options[option].setFillColor(Color::White); option++;

        if (option == 4){ option = 0;}

        options[option].setFillColor(Color::Yellow);
    }
}