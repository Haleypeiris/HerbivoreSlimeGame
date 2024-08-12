#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteClass.h"

#define SPRITE_BODY 32
#define END_OF_SPRITE_SHEET 224

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
	sf::Clock m_animationTimer;


	//animation
	short m_animation_state;
	void initAnimations();

	//movement
	bool m_movement;
	void updateMovement();

	//core
	void initVariables();
	
	//Physics
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

