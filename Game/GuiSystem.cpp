#include "GuiSystem.h"

GuiSystem::GuiSystem(HungerManager* hunger)
{
    this->m_hunger_levels = hunger;
    this->initHungerBar();
    this->updateHungerBar();
}

void GuiSystem::initHungerBar()
{
    //Set GUI Bar
    m_hunger_bar_max_width = 100.f;
    this->m_hunger_bar_back.setSize(sf::Vector2f(100.f, 20.f));
    this->m_hunger_bar_back.setFillColor(sf::Color(50, 50, 50, 200));
    this->m_hunger_bar_back.setPosition(600.f, 10.f);

    this->m_hunger_bar_inner.setSize(sf::Vector2f(100.f, 20.f));
    this->m_hunger_bar_inner.setFillColor(sf::Color(250, 50, 50, 200));
    this->m_hunger_bar_inner.setPosition(this->m_hunger_bar_back.getPosition());

}
void GuiSystem::renderHungerBar(sf::RenderTarget& target)
{
    target.draw(this->m_hunger_bar_back);
    target.draw(this->m_hunger_bar_inner);
}
void GuiSystem::updateHungerBar()
{
    //ensures
    float percent = static_cast<float>(this->m_hunger_levels->getHungerLevels()) / static_cast<float>(this->m_hunger_levels->m_max_hunger_levels);
    std::cout << (percent) << std::endl;
    this->m_hunger_bar_inner.setSize(
        sf::Vector2f(static_cast<float>(std::floor(this->m_hunger_bar_max_width * percent)),
            this->m_hunger_bar_inner.getSize().y));
}