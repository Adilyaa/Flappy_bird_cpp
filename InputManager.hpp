#pragma once

#include <SFML/Graphics.hpp>

namespace Sonar
{
    class InputManager
    {
    public:
        InputManager( ) { }
        ~InputManager( ) { }
        
        bool IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow  &window );
        
        //return type
        sf::Vector2i GetMousePosition( sf::RenderWindow &window );
        
    };
}
