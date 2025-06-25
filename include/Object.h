#pragma once  
#include <SFML/Graphics.hpp>  
#include "Texture.h"  


class Player;
class EnemyCar;

class Object  
{  
public:  
   Object(std::string name, sf::Vector2f pos);  
 
   virtual void collision(Object* other) {};  
   virtual void collided(Object* other) {}; 
   virtual void collided(Player* player) {}
   virtual void collided(EnemyCar* enemyCar) {}
   virtual void draw(sf::RenderWindow& window);

   ~Object() {};  
   sf::FloatRect getGlobal() const { return m_sprite.getGlobalBounds(); }

protected:  
   sf::Sprite m_sprite;  

private:  
};
