#pragma once
#include "DayCycle.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>

#include "Common.h"

void daycycle_timer(Daycycle &daycycle, sf::Clock &clock);
bool change_in_time(Daycycle& daycycle);