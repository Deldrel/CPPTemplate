#include "Core.h"

Core::Core() = default;

Core::~Core() {
    println("Leaving...");
    ImGui::SFML::Shutdown();
    println(" Done!");
}

int Core::init() {
    println("Initializing...");

    window.create(sf::VideoMode(width, height), "Core", sf::Style::Close);
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
    //IOThemeEmbraceTheDarkness();

    assert(spriteManager.init());

    println(" Done!");
    return 1;
}

void Core::run() {
    sf::Time elapsedTime = sf::Time::Zero;

    while (window.isOpen()) {
        elapsedTime += m_deltaClock.restart();

        if (elapsedTime > sf::seconds(1.f / loop_limit)) {
            handleEvents();
            ImGui::SFML::Update(window, m_deltaClock.restart());
            display();
        }
    }
}

void Core::handleEvents() {
    while (window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(window, event);

        switch (event.type) {

            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) window.close();
                break;
        }
    }
}

void Core::display() {
    window.clear();
    imgui();
    ImGui::SFML::Render(window);
    
    window.draw(spriteManager.getSprite(Pieces));

    window.display();
}

void Core::imgui() {
    //ImGui::ShowMetricsWindow();
}