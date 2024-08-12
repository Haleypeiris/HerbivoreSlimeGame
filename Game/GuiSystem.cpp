#include "GuiSystem.h"

GuiSystem::GuiSystem(HungerManager* hunger)
{
    hunger_levels = hunger;
    this->init_hp_bar();
    this->update_hp_bar();
}

void GuiSystem::init_hp_bar()
{
    hp_bar_max_width = 100.f;
    this->hp_bar_back.setSize(sf::Vector2f(100.f, 20.f));
    this->hp_bar_back.setFillColor(sf::Color(50, 50, 50, 200));
    this->hp_bar_back.setPosition(600.f, 10.f);

    this->hp_bar_inner.setSize(sf::Vector2f(100.f, 20.f));
    this->hp_bar_inner.setFillColor(sf::Color(250, 50, 50, 200));
    this->hp_bar_inner.setPosition(this->hp_bar_back.getPosition());

}
void GuiSystem::render_hp_bar(sf::RenderTarget& target)
{
    target.draw(this->hp_bar_back);
    target.draw(this->hp_bar_inner);
}

void GuiSystem::render(sf::RenderTarget& target)
{
    this->render_hp_bar(target);
}
void GuiSystem::update_hp_bar()
{
    float percent = static_cast<float>(hunger_levels->get_hunger_levels()) / static_cast<float>(hunger_levels->max_hunger_levels);
    std::cout << (percent) << std::endl;
    this->hp_bar_inner.setSize(
        sf::Vector2f(static_cast<float>(std::floor(this->hp_bar_max_width * percent)),
            this->hp_bar_inner.getSize().y));
}