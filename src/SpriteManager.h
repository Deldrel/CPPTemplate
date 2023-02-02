#ifndef TEMPLATE_SPRITEMANAGER_H
#define TEMPLATE_SPRITEMANAGER_H

#include "Libraries.h"
#include "ResourceHolder.h"

class SpriteManager {

private:

    ResourceHolder<sf::Texture, ID> textures;

    std::unordered_map<ID, std::unique_ptr<sf::Sprite>> sprites;

    void loadTextures();

    void loadSprites();

    void addSprite(ID id);

public:

    SpriteManager();

    ~SpriteManager();

    int init();

    sf::Sprite getSprite(ID id);

};


#endif
