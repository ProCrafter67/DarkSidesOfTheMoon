#include "Game.hpp"

namespace Game
{
	Game::Game()
	{
		win = new Window();
	}

	void Game::Run()
	{
		while (win->IsOpen())
		{
			win->Update();
		}
	}
}