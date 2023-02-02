#include "SpriteManager.h"

SpriteManager::SpriteManager() = default;

SpriteManager::~SpriteManager() {
    auto it1 = sprites.begin();
    while (it1 != sprites.end())
        sprites.erase(it1++);
}

int SpriteManager::init() {
    try {
        loadTextures();
        loadSprites();
    }
    catch (std::runtime_error &e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return 0;
    }
    return 1;
}

void SpriteManager::loadTextures() {
    textures.load(Pieces, "../../resources/textures/pieces.png", {600, 200});
}

void SpriteManager::loadSprites() {
    addSprite(Pieces);
}

void SpriteManager::addSprite(ID id) {
    std::unique_ptr<sf::Sprite> sprite(new sf::Sprite());
    sprite->setTexture(textures.get(Pieces));
    auto inserted = sprites.insert(std::make_pair(id, std::move(sprite)));
    assert(inserted.second);
}

sf::Sprite SpriteManager::getSprite(ID id) {
    auto found = sprites.find(id);
    assert(found != sprites.end());
    return *found->second;
}