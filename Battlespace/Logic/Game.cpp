
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

void Game::combat_update()
{

    // windows bounds


    // collide with enemy

}

void Game::update()
{
    player->update(this->window->getSize());

    // Bullets update
    for (size_t i = 0; i < this->player->getBullets().size(); i++)
    {
        this->player->getBullets()[i].update();

        // Windows bounds check
        if (this->player->getBullets()[i].getPosition().x > this->window->getSize().x)
        {
            // erase the bullet
            this->player->getBullets().erase(this->player->getBullets().begin());
        }

        // Enemy collisions check

    }
}

void Game::draw()
{
    window->clear();

    player->draw(*window);

    window->display();
}
