#pragma once
#include "Player.h"
#include <vector>
#include <algorithm>

class ScoreBoard
{
public:
	void showScoreBoard(const std::vector<const Player*>& globalPlayers);
};

