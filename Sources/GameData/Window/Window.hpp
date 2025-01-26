#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>

#define BUFF_DEFAULT_WIDTH 800
#define BUFF_DEFAULT_HEIGHT 600
#define BUFF_DEFAULT_TITLE "Buff Engine v0.1.0"

namespace Game
{
	class Window
	{
	public:
		Window();
		~Window();

		bool IsOpen();
		void Update();

		void SetTitle(const char* title);
		void SetSize(int width, int height);

		int GetWidth();
		int GetHeight();
		GLFWwindow* GetHandle();
		const char* GetTitle();

	private:
		GLFWwindow* Handle;

		static void SizeCallback(GLFWwindow* window, int width, int height);
	};
}