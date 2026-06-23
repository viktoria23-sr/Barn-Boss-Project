#include "ShowScoreboardCommand.h"
#include "Game.h"

void ShowScoreboardCommand::execute(const std::vector<std::string>& args)
{
	game.showScoreboard();
}
