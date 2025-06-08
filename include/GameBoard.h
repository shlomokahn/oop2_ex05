#include <SFML/Graphics.hpp>
class GameBoard
{
public:
	GameBoard();
	~GameBoard();

protected:
	void runBoard();
	void openWindow(const sf::Vector2u size);
	bool isOpen();
	
private:
	void drawBoard();
	void drawRoad(int roadWidthBottom, int roadWidthTop);
	sf::RenderWindow m_window;
};