
#include "../Headers/EnemySpawner.h"

void EnemySpawner::create_enemy(int limit)
{
    // Set value
    srand((unsigned) time(NULL));

    enemy_texture.loadFromFile("../Assets/enemy.png");

    int xpos = 1475, ypos, health = 100, idm;

    for (int i = 1; i < limit; i++)
    {
        // get random number 0 or 1
        idm = 0 + (rand() % 2);
        // get random y position
        ypos = 0 + (rand() % 900);

        this->insert_enemy(&this->enemy_texture, i, xpos, ypos, health, idm);
    }
}


void EnemySpawner::insert_enemy(Texture *texture, int data, int x_pos, int y_pos, int health, int idm)
{

    Enemy *enemy = new Enemy(texture, data, x_pos, y_pos, health, idm);

    if (head == NULL){head = enemy; return;}

    Enemy *aux = head;

    while (aux->next != NULL){aux = aux->next;}

    aux->next = enemy;
}

void EnemySpawner::print_enemy_list()
{
    Enemy* aux = head;

    // Check for empty list.
    if (head == NULL) {std::cout << "List empty" << std::endl; return;}

    // Traverse the list.
    while (aux != NULL)
    {
        std::cout << aux->id << " ";
        std::cout << aux->x_pos << " ";
        std::cout << aux->y_pos << " ";
        std::cout << aux->health << " ";
        std::cout << aux->movement << " ";
        std::cout << aux << "\n";

        aux = aux->next;
    }
}

void EnemySpawner::spawn_enemies(RenderTarget &target)
{
    Enemy* aux = head;

    // Check for empty list.
    if (head == NULL) {std::cout << "List empty" << std::endl; return;}

    // Traverse the list.
    while (aux != NULL)
    {
        aux->draw(target);
        aux = aux->next;
    }
}

void EnemySpawner::move_enemies()
{
    Enemy* aux = head;

    // Check for empty list.
    if (head == NULL) {std::cout << "List empty" << std::endl; return;}

    // Traverse the list.
    while (aux != NULL)
    {
        aux->move(aux->movement);
        aux = aux->next;
    }
}