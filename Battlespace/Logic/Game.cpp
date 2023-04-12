
#include "../Headers/Game.h"

Game::Game(RenderWindow *window)
{
    this->window = window;
    this->window->setFramerateLimit(60);

    // Init texture
    player_texture.loadFromFile("../Assets/player.png");

    // Init player
    player = new Player(&this->player_texture);
    player2 = new Player(&this->player_texture);
}

Game::~Game()
{
    delete player;
    delete player2;
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
