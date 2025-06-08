#pragma once
#include "GameBoard.h"


//===============================
GameBoard::GameBoard()
    : m_object("resources/car.png", sf::Vector2f(500, 500))
{
}
//===============================
GameBoard::~GameBoard()
{
}
//===============================
void GameBoard::runBoard()
{	
	m_window.clear(sf::Color(100, 180, 80));
    drawBoard();
}
//===============================
void GameBoard::openWindow(const sf::Vector2u size)
{
	m_window.create(sf::VideoMode(size.x, size.y), "Game Board");
	m_window.setFramerateLimit(60);
}
//===============================
bool GameBoard::isOpen()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
			return false;
		}
	}
	m_object.draw(m_window);
	m_window.display();
	return true;
	
}
//===============================
void GameBoard::drawBoard()
{
	drawRoad(1400, 300);
}
//===============================
void GameBoard::drawRoad(int roadWidthBottom, int roadWidthTop) {
    int winWidth = m_window.getSize().x;
    int winHeight = m_window.getSize().y;

    // ציור המשולש (הכביש)
    sf::ConvexShape road;
    road.setPointCount(4);
    road.setPoint(0, sf::Vector2f((winWidth - roadWidthTop) / 2, 0)); // למעלה שמאל
    road.setPoint(1, sf::Vector2f((winWidth + roadWidthTop) / 2, 0)); // למעלה ימין
    road.setPoint(2, sf::Vector2f((winWidth + roadWidthBottom) / 2, winHeight)); // למטה ימין
    road.setPoint(3, sf::Vector2f((winWidth - roadWidthBottom) / 2, winHeight)); // למטה שמאל
    road.setFillColor(sf::Color(30, 30, 30)); // שחור-אפור

    m_window.draw(road);

    // ציור קווים לבנים (קו מקווקו במרכז)
    int numLines = 12;
    for (int i = 0; i < numLines; ++i) {
        float t1 = float(i) / numLines;
        float t2 = float(i + 0.5f) / numLines;

        float y1 = t1 * winHeight;
        float y2 = t2 * winHeight;

        float xCenter = winWidth / 2;

        sf::RectangleShape line(sf::Vector2f(6, y2 - y1));
        line.setFillColor(sf::Color::White);
        line.setOrigin(3, 0);
        line.setPosition(xCenter, y1);
        m_window.draw(line);
    }

    // ציור שני קווים עקומים (שוליים פנימיים) ל-4 נתיבים
    int numCurvePoints = 2; // כמה נקודות בכל קו
    for (int lane = 1; lane <= 2; ++lane) {
        sf::VertexArray curve(sf::LineStrip, numCurvePoints);
        for (int i = 0; i < numCurvePoints; ++i) {
            float t = float(i) / (numCurvePoints - 1);
            float y = t * winHeight;
            float roadWidthAtY = roadWidthTop + (roadWidthBottom - roadWidthTop) * t;
            float x = (winWidth - roadWidthAtY) / 2 + (roadWidthAtY / 4) * lane;
            curve[i].position = sf::Vector2f(x, y);
            curve[i].color = sf::Color::White;
        }
        m_window.draw(curve);

        // קו סימטרי בצד השני
        sf::VertexArray curve2(sf::LineStrip, numCurvePoints);
        for (int i = 0; i < numCurvePoints; ++i) {
            float t = float(i) / (numCurvePoints - 1);
            float y = t * winHeight;
            float roadWidthAtY = roadWidthTop + (roadWidthBottom - roadWidthTop) * t;
            float x = (winWidth + roadWidthAtY) / 2 - (roadWidthAtY / 4) * lane;
            curve2[i].position = sf::Vector2f(x, y);
            curve2[i].color = sf::Color::White;
        }
        m_window.draw(curve2);
    }
}
