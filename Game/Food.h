#pragma once

#include "InteractionArea.h"
#include "Common.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <iostream>
class Food : public InteractionArea
{
private:
	Daycycle m_eatingtime;
	std::string m_filepath;
	sf::Texture m_texture;

public:
	sf::Sprite m_sprite;
	Food(int xpos, int ypos, int width, int height, std::string name, Daycycle time, std::string texture);
	~Food();
	bool canFoodBeEatenNow(Daycycle time);
	void initSprite();
	void initTexture();
	void render(sf::RenderTarget& target);

};

