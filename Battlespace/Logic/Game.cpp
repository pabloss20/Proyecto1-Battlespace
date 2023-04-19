
#include <iostream>
#include "../Headers/Game.h"

Game::Game()
{
    // Init texture
    player_texture.loadFromFile("../Assets/player.png");
    bullet_texture.loadFromFile("../Assets/bullet.png");

    // Init player
    player = new Player(&this->player_texture, &bullet_texture);

    enemySpawner = new EnemySpawner();
}

void Game::start()
{
    Vector2i center_window((VideoMode::getDesktopMode().width / 2 - 650), (VideoMode::getDesktopMode().height / 2));
    RenderWindow window(VideoMode(1500, 1000), "Battlespace", Style::Default);
    window.setPosition(center_window);

    // Background
    Texture background;
    Sprite background_sprite;

    if (!background.loadFromFile("../Assets/sky.jpg"))std::cout << "NOT IMAGE FOUND";

    background_sprite.setTexture(background);

    Sprite sprite;

    enemySpawner->create_enemy(5);
    int limit = enemySpawner->getSize();

    for (int i = 0; i < limit; i++)
    {

    }
    std::cout << limit;

    //enemy = enemySpawner->print_enemy_list();
    //enemy->draw(window);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) { window.close(); break;}
            if (event.type == Event::KeyPressed) {if (event.key.code == Keyboard::Escape) { window.close(); break;}}
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Up){

                    this->update(&window, 1);
                    this->player->shoot(window);

                }
                if (event.key.code == Keyboard::Down) {

                    this->update(&window, 2);

                    bullet = this->player->shoot(window);

                    bullet->draw(window);
                }
            }
        }

        window.draw(background_sprite);
        this->draw(&window);
        //enemySpawner->spawn_enemies(window);
        //enemySpawner->move_enemies(&window);
        window.display();
    }
}

void Game::combat_update()
{

    // windows bounds


    // collide with enemy

}

void Game::update(RenderWindow *window, int num)
{
    player->update(window->getSize(), *window, num);
}

void Game::draw(RenderWindow *window)
{

    player->draw(*window);
}
