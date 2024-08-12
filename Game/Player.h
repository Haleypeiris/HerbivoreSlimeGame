#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include "SpriteClass.h"

enum Player_Animation_States
{
	Player_Idle = 0,
	Player_Moving_Left,
	Player_Moving_Right,
	Player_Moving_Up,
	Player_Moving_Down
};

class Player : public SpriteClass
{
private:
	sf::Vector2f m_pos;
	sf::IntRect m_currentFrame;
	short m_animation_state;
	bool m_movement;
	sf::Clock animationTimer;

	//animation
	void initAnimations();

	//movement
	void updateMovement();
	void run();
	//core
	void initVariables();
	sf::Vector2f m_velocity;
	float m_acceleration;
	float m_drag;
	float m_max_velocity;
	float m_min_velocity;
	void initPhysics();
public:
	Player(const std::string& text);
	~Player();
	void update();
	void updateAnimations();
	void updatePhysics();
	void move(const float dir_x, const float dir_y);
	void updatePos();
	sf::Vector2f getPos();


};

