
#ifndef BATTLESPACE_BULLET_H
#define BATTLESPACE_BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Bullet
{
public:

    Bullet(){id = 0; next = NULL;}
    Bullet(Texture *texture, Vector2f position, Vector2f max_velocity = Vector2f (10.f, 0.f));
    virtual ~Bullet();

    void update();
    void draw(RenderTarget &target);

    void move();

    int damage;
    int id;
    void setDamage(int);
    int getDamage();

    Bullet *next;

    // Accesors
    inline const FloatRect& getGlobalBounds() const {return this->sprite.getGlobalBounds();}
    inline const Vector2f& getPosition() const {return this->sprite.getPosition();}

private:

    Sprite sprite;
    Texture *texture;

    Vector2f max_velocity;
};

#endif //BATTLESPACE_BULLET_H
