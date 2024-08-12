#pragma once

enum Daycycle
{
	Daycycle_Unknown = -1,
	Daycycle_Morning = 0,
	Daycycle_Afternoon,
	Daycycle_Night
};

enum GameState
{
	GameState_Start = 0,
	GameState_Running,
	GameState_End
};