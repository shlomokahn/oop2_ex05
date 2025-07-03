#pragma once  
#include <SFML/Graphics.hpp>  
#include "Texture.h"  


class Player;
class EnemyCar;
class Block;

class Object  
{  
public:  
   Object(std::string name, sf::Vector2f pos);  
 
   virtual void collision(Object* other) {}
   virtual void collided(Player* player) {}
   virtual void collided(EnemyCar* enemyCar) {}
   virtual void collided(Block* block) {}
   virtual void draw(sf::RenderWindow& window);
   void setScale(float x, float y);

   ~Object() {};  
   sf::FloatRect getGlobal() const { return m_sprite.getGlobalBounds(); }

protected:  
   sf::Sprite m_sprite;  

private:  
};
