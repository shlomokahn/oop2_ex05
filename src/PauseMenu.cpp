#include "PauseMenu.h"

// פקודה להמשך
class ResumeCommand : public Command {
public:
    ResumeCommand(bool& resumeFlag) : m_resume(resumeFlag) {}
    void execute(sf::RenderWindow&) override {
        m_resume = true;
    }
private:
    bool& m_resume;
};

// פקודה ליציאה
class ExitCommand : public Command {
public:
    ExitCommand(bool& exitFlag) : m_exit(exitFlag) {}
    void execute(sf::RenderWindow&) override {
        m_exit = true;
    }
private:
    bool& m_exit;
};

PauseMenu::PauseMenu(sf::RenderWindow& window)
    : m_window(window)
{
    auto center = sf::Vector2f(window.getSize()) / 2.f;

    // רקע שקוף שחור
    m_background.setSize(sf::Vector2f(400, 300));
    m_background.setFillColor(sf::Color(0, 0, 0, 180));
    m_background.setPosition(center - m_background.getSize() / 2.f);

    // כפתורים
    sf::Vector2f buttonSize(200, 60);

    m_menu.add("Resume", std::make_unique<ResumeCommand>(/*ref*/ *(new bool(false))), buttonSize, { center.x - 100, center.y - 50 });
    m_menu.add("Exit", std::make_unique<ExitCommand>(/*ref*/ *(new bool(false))), buttonSize, { center.x - 100, center.y + 30 });
}

void PauseMenu::draw()
{
    m_window.draw(m_background);
    m_menu.draw(m_window);
}

void PauseMenu::handleEvent(const sf::Event& event, bool& resume, bool& exit)
{
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(m_window);

        // צור מחדש את התפריט עם הפניות תקינות ל־resume ול־exit
        Menu tempMenu;
        tempMenu.add("Resume", std::make_unique<ResumeCommand>(resume), { 200, 60 }, { m_window.getSize().x / 2.f - 100, m_window.getSize().y / 2.f - 50 });
        tempMenu.add("Exit", std::make_unique<ExitCommand>(exit), { 200, 60 }, { m_window.getSize().x / 2.f - 100, m_window.getSize().y / 2.f + 30 });

        tempMenu.maneger(m_window, mousePos);
    }
}
