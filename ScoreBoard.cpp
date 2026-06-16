#include "ScoreBoard.h"

void ScoreBoard::showScoreBoard(const std::vector<Player>& globalPlayers)
{
	std::println("        || SCOREBOARD ||        ");

	if (globalPlayers.empty())
	{
		std::println("No players registered yet.");
		return;
	}

	std::vector<Player> sortedPlayers = globalPlayers;

	for (size_t i = 0; i < sortedPlayers.size() - 1; i++)
	{
		for (size_t j = 0; j < sortedPlayers.size() - i - 1; j++)
		{
			if (sortedPlayers[j] < sortedPlayers[j + 1])
			{
				std::swap(sortedPlayers[j], sortedPlayers[j + 1]);
			}
		}
	}

	for (size_t i = 0; i < sortedPlayers.size(); ++i)
	{
		const auto& player = sortedPlayers[i];
		
		std::println("{}. {} | Score: {} | Balance: {}",
			i + 1,
			player.getUsername(),
			player.checkScore(),
			player.checkBalance());
	}
}

