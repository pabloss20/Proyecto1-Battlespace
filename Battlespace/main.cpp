
#include <iostream>
#include "Headers/Game.h"

int main()
{

    Vector2i center_window((VideoMode::getDesktopMode().width / 2 - 650), (VideoMode::getDesktopMode().height / 2));
    RenderWindow window(VideoMode(1500, 1000), "Battlespace", Style::Default);
    window.setPosition(center_window);

    // Background
    Texture background;
    Sprite background_sprite;

    if (!background.loadFromFile("../Assets/bg1.png"))std::cout << "NOT IMAGE FOUND";

    background_sprite.setTexture(background);

    while (window.isOpen())
    {

        Font font_text;
        if (!font_text.loadFromFile("../Assets/font.otf")) std::cout << "NOT FONT FOUND";

        Texture easy_btn, normal_btn, expert_btn;
        Sprite easy_spr, normal_spr, expert_spr;

        if (!easy_btn.loadFromFile("../Assets/bsf.png")) std::cout << "NOT IMAGE FOUND";
        if (!normal_btn.loadFromFile("../Assets/bsf.png")) std::cout << "NOT IMAGE FOUND";
        if (!expert_btn.loadFromFile("../Assets/bsf.png")) std::cout << "NOT IMAGE FOUND";

        easy_spr.setPosition(550.0f, 250.0f);
        normal_spr.setPosition(550.0f, 400.0f);
        expert_spr.setPosition(550.0f, 550.0f);

        float easy_btn_width = easy_spr.getLocalBounds().width;
        float easy_btn_height = easy_spr.getLocalBounds().height;
        float normal_btn_width = normal_spr.getLocalBounds().width;
        float normal_btn_height = normal_spr.getLocalBounds().height;
        float expert_btn_width = expert_spr.getLocalBounds().width;
        float expert_btn_height = expert_spr.getLocalBounds().height;

        easy_spr.setTexture(easy_btn);
        normal_spr.setTexture(normal_btn);
        expert_spr.setTexture(expert_btn);

        Text text_ea, text_no, text_ex;
        text_ea.setFont(font_text);
        text_no.setFont(font_text);
        text_ex.setFont(font_text);

        text_ea.setFillColor(Color::Black);
        text_no.setFillColor(Color::Black);
        text_ex.setFillColor(Color::Black);

        text_ea.setStyle(Text::Bold);
        text_no.setStyle(Text::Bold);
        text_ex.setStyle(Text::Bold);

        text_ea.setString("EASY");
        text_no.setString("NORMAL");
        text_ex.setString("EXPERT");

        text_ea.setPosition(690.0f, 290.0f);
        text_no.setPosition(690.0f, 440.0f);
        text_ex.setPosition(690.0f, 590.0f);

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (easy_spr.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
            {
                text_ea.setFillColor(Color::Yellow);
            }
            if (normal_spr.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
            {
                text_no.setFillColor(Color::Yellow);
            }
            if (expert_spr.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
            {
                text_ex.setFillColor(Color::Yellow);
            }
        }

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) { window.close(); break;}
            if (event.type == Event::KeyPressed) {if (event.key.code == Keyboard::Escape) { window.close(); break;}}
        }

        window.clear();
        window.draw(background_sprite);
        window.draw(easy_spr);
        window.draw(normal_spr);
        window.draw(expert_spr);
        window.draw(text_ea);
        window.draw(text_no);
        window.draw(text_ex);

        /*
        window.draw(sprite_ea);
        window.draw(sprite_no);
        window.draw(sprite_ex);
        window.draw(sprite_qu);
        window.draw(text_ea);
        window.draw(text_no);
        window.draw(text_ex);
        window.draw(text_qu);
        */
        window.display();
    }
}
/*
    game.update();
    game.draw();

*/
