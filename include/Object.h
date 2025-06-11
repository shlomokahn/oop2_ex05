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

   virtual void draw(sf::RenderWindow& window);
   void setRect(const float rotation);
   ~Object() {};  
   sf::FloatRect getGlobal() const { return m_sprite.getGlobalBounds(); }
   //const sf::Sprite& getSprite() const { return m_sprite; }  

protected:  
   void setSise(const float scale);  
   sf::Vector2f m_toMove = { 0,0 };

private:  
   sf::Sprite m_sprite;  
};
