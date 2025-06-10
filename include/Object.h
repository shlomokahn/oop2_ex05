#pragma once  
#include <SFML/Graphics.hpp>  
#include "Texture.h"  

class Object  
{  
public:  
   Object(std::string name, sf::Vector2f pos);  

   virtual void action(const float time);  
   virtual void collision(Object& other) {};  
   virtual void collided(Object& other) {};  

   void draw(sf::RenderWindow& window);  
   void setRect(const float rotation);
   ~Object() {};  

   const sf::Sprite& getSprite() const { return m_sprite; }  

protected:  
   void setSise(const float scale);  
   sf::Sprite m_sprite;  

private:  
};
