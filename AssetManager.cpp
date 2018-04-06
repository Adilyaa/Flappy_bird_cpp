#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

namespace Sonar
{
    void AssetManager::LoadTexture(std::string name, std::string filename )
    {
        sf::Texture tex;
        
        if ( tex.loadFromFile( filename ) )
        {
            // add it to the map of textures that we already have
            this->_textures[name] = tex;
        }
        
    }
    sf::Texture &AssetManager::GetTexture( std::string name )
    {
        return this->_textures.at( name );
    }
}
//do the same for fonts

    void Sonar::AssetManager::LoadFont(std::string name, std::string filename )
    {
        sf::Font font;
    
        if ( font.loadFromFile( filename ) )
        {
        // add it to the map of textures that we already have
            this->_fonts[name] = font;
        }
    
    }
    sf::Font &Sonar::AssetManager::GetFont( std::string name )
    {
    return this->_fonts.at( name );
}









