#pragma once
#include "DayCycle.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>

#include "Common.h"

void daycycleTimer(Daycycle &daycycle, sf::Clock &clock);
bool changeInTime(Daycycle& daycycle);