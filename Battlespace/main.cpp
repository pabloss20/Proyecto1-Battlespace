
#include "Headers/Game.h"
#include "Headers/Menu.h"

int main() {

    RenderWindow window(VideoMode(1500, 1000), "Battlespace", Style::Default);
    Menu menu(1500, 1000);

    Texture background;

    while (true) {
        while (window.isOpen()) {
            Event event;

            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                    break;
                }

                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Up) { menu.move_up(); }
                    if (event.key.code == Keyboard::Down) { menu.move_down(); }
                }
            }
            window.clear();
            menu.draw(window);
            window.display();
        }
    }
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
