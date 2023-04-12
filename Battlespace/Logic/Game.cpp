
#include "../Headers/Game.h"

Game::Game(RenderWindow *window)
{
    this->window = window;
    this->window->setFramerateLimit(60);

    // Init texture
    player_texture.loadFromFile("../Assets/player.png");
    bullet_texture.loadFromFile("../Assets/bullet.png");

    // Init player
    player = new Player(&this->player_texture, &bullet_texture);
}

Game::~Game()
{
    delete player;
}

void Game::update()
{
    player->update();
}

void Game::draw()
{
    window->clear();

    player->draw(*window);

    window->display();
}
