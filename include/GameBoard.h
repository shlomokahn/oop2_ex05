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
	sf::RenderWindow m_window;
};