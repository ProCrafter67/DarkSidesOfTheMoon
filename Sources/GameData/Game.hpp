#pragma once

#include "Window/Window.hpp"

namespace Game
{
	class Game
	{
	public:
		Game();

		void Run();

	private:
		Window* win;
	};
}