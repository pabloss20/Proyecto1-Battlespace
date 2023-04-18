
#include <iostream>
#include "Headers/Game.h"

int main() {

    Vector2i center_window((VideoMode::getDesktopMode().width / 2 - 650), (VideoMode::getDesktopMode().height / 2));
    RenderWindow window(VideoMode(1500, 1000), "Battlespace", Style::Default);
    window.setPosition(center_window);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(true);

    // Background
    RectangleShape bg;
    bg.setSize(Vector2f(1500, 1000));
    Texture texture;
    texture.loadFromFile("../Assets/bg1.png");
    bg.setTexture(&texture);

    // Buttons sprites
    Texture texture_buttons;
    texture_buttons.loadFromFile("../Assets/bsx.png");

    Sprite sprite_ea, sprite_no, sprite_ex, sprite_qu;
    sprite_ea.setPosition(500, 50);
    sprite_no.setPosition(500, 200);
    sprite_ex.setPosition(500, 350);
    sprite_qu.setPosition(500, 500);

    sprite_ea.setTexture(texture_buttons);
    sprite_no.setTexture(texture_buttons);
    sprite_ex.setTexture(texture_buttons);
    sprite_qu.setTexture(texture_buttons);

    sprite_ea.setScale(200.f, 100.f);

    // Text for buttons
    Font font;
    font.loadFromFile("../Assets/font.otf");

    Text text_ea, text_no, text_ex, text_qu;
    text_ea.setFont(font);
    text_no.setFont(font);
    text_ex.setFont(font);
    text_qu.setFont(font);

    text_ea.setFillColor(Color::Black);
    text_no.setFillColor(Color::Black);
    text_ex.setFillColor(Color::Black);
    text_qu.setFillColor(Color::Black);

    text_ea.setString("EASY");
    text_no.setString("NORMAL");
    text_ex.setString("EXPERT");
    text_qu.setString("QUIT");

    text_ea.setPosition(690, 275);
    text_no.setPosition(690, 375);
    text_ex.setPosition(690, 475);
    text_qu.setPosition(690, 575);

    while (true)
    {
        while (window.isOpen())
        {

            if (sprite_ea.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
            {
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    std::cout << "1";
                }
            }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (sprite_no.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                {
                    std::cout << "2" << "\n";
                }
                if (sprite_ex.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                {
                    std::cout << "3" << "\n";
                }
                if (sprite_qu.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                {
                    window.clear();
                    window.close();
                    break;

                }
            }

            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed) { window.close(); break;}
                if (event.type == Event::KeyPressed) {if (event.key.code == Keyboard::Escape) { window.close(); break;}}
            }

            window.clear();
            window.draw(bg);
            window.draw(sprite_ea);
            window.draw(sprite_no);
            window.draw(sprite_ex);
            window.draw(sprite_qu);
            window.draw(text_ea);
            window.draw(text_no);
            window.draw(text_ex);
            window.draw(text_qu);
            window.display();
        }
        break;
    }
    return 0;
}
    /*
    // Background
    RectangleShape bg;
    bg.setSize(Vector2f(1500, 1000));
    Texture texture;
    texture.loadFromFile("../Assets/bg1.png");
    bg.setTexture(&texture);

    //Menu menu(window.getSize().x, window.getSize().y);
    Game game(&window);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();

            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::Up){
                    //menu.move_up();
                    break;
                }
                if (event.key.code == Keyboard::Down)
                {
                    //menu.move_down();
                    break;
                }
                if (event.key.code == Keyboard::BackSpace)
                {
                    RenderWindow Easy(VideoMode(1500, 1000), "Battlespace - Game");
                    RenderWindow Normal(VideoMode(1500, 1000), "Battlespace - Game");
                    RenderWindow Expert(VideoMode(1500, 1000), "Battlespace - Game");
                    RenderWindow Exit(VideoMode(1500, 1000), "Battlespace - Game");

                    //int x = menu.menu_pressed();

                    if (x == 0)
                    {
                        while (Easy.isOpen())
                        {
                            Event aevent;
                            while (Easy.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                {
                                    Easy.close();
                                }
                                if (aevent.type == Event::KeyPressed)
                                {
                                    if (aevent.key.code == Keyboard::Escape)
                                    {
                                        Easy.close();
                                    }
                                    if (aevent.key.code == Keyboard::Enter)
                                    {

                                        std::cout << "wef";
                                        window.clear();
                                        game.update();
                                        game.draw();
                                    }
                                }
                            }
                            window.clear();
                            Normal.close();
                            Expert.close();
                            Easy.clear();
                            Easy.display();
                        }
                    }
                    if (x == 1)
                    {
                        while (Normal.isOpen())
                        {
                            Event aevent;
                            while (Normal.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                {
                                    Normal.close();
                                }
                                if (aevent.type == Event::KeyPressed)
                                {
                                    if (aevent.key.code == Keyboard::Escape)
                                    {
                                        Normal.close();
                                    }
                                }
                            }
                            Easy.close();
                            Expert.close();
                            Normal.clear();
                            Normal.display();
                        }
                    }
                    if (x == 2)
                    {
                        while (Expert.isOpen())
                        {
                            Event aevent;
                            while (Expert.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                {
                                    Expert.close();
                                }
                                if (aevent.type == Event::KeyPressed)
                                {
                                    if (aevent.key.code == Keyboard::Escape)
                                    {
                                        Expert.close();
                                    }
                                }
                            }
                            Easy.close();
                            Normal.close();
                            Expert.clear();
                            Expert.display();
                        }
                    }

                    if (x == 3){window.close();}
                }
            }
        }

        game.update();
        game.draw();
    }
    */
