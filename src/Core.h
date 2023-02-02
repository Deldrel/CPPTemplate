#ifndef TEMPLATE_CORE_H
#define TEMPLATE_CORE_H

#include "Libraries.h"
#include "SpriteManager.h"

class Core {

private:

    sf::RenderWindow window;

    sf::Event event{};

    sf::Clock m_deltaClock;

    SpriteManager spriteManager;

public:

    Core();

    ~Core();

    int init();

    void run();

    void handleEvents();

    void display();

    void imgui();
};


#endif
