#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <set>
#include <stdlib.h> 

#include "Common.h"
#include "DayCycle.h"
#include "HungerManager.h"
#include "InteractionArea.h"
#include "GuiSystem.h"
#include "Food.h"
#include "SpriteClass.h"
#include "Player.h"


class Game
{
private:
	sf::RenderWindow* m_window;
	sf::VideoMode m_video_mode;
	sf::Event m_ev;
	sf::Vector2i m_mouse_pos;
	sf::Clock m_clock;
	sf::Clock m_temp_clock;
	std::set<std::shared_ptr<Food>> m_food_items;
	std::string m_food_names[5];
	sf::Text m_text;
	sf::Font m_font;

	GameState m_gamestate= GameState_Start;

	SpriteClass* m_background;
	HungerManager* m_hunger_levels;
	GuiSystem* m_gui;
	Player* m_player;
	Daycycle m_time_of_day;


	void initVariables();
	void initHungerLevels();
	void initWindow();
	void initFoodList();
	void initText();
	void deleteFoodList();
	void initBackground();
	void initPlayer();
public:
	Game();
	virtual ~Game();
	const bool getWindowIsOpen() const;
	void pollEvents();
	void update();
	void updatePlayer();
	void render();
	void renderPlayer();
	void mousePos();
	void worldClock();
	void addToFoodList();
	void change_background_color(Daycycle time);
	void renderText(sf::RenderTarget& target);
	void startMenu();
	void endMenu();
};

