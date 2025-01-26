#include <glad/glad.h>
#include "Window.hpp"

namespace Game
{
	Window::Window()
	{
		glfwInit();

#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

		std::cerr << "Creating Window ..." << std::endl;

		Handle = glfwCreateWindow(BUFF_DEFAULT_WIDTH, BUFF_DEFAULT_HEIGHT, BUFF_DEFAULT_TITLE, nullptr, nullptr);

		if (Handle == NULL) {
			std::cerr << "Failed to create Window ..." << std::endl;
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		glfwSetFramebufferSizeCallback(Handle, SizeCallback);
		glfwMakeContextCurrent(Handle);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cerr << "Failed to load OpenGL ..." << std::endl;
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		std::cerr << "Window and Window Surface created successfully ..." << std::endl;
	}

	Window::~Window()
	{
		std::cerr << "Destroying Window ..." << std::endl;
		glfwDestroyWindow(Handle);
		glfwTerminate();
	}

	bool Window::IsOpen()
	{
		return !glfwWindowShouldClose(Handle);
	}

	void Window::Update()
	{
		glfwSwapBuffers(Handle);
		glfwPollEvents();
	}

	void Window::SizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	// Getters and Setters

	void Window::SetTitle(const char* title)
	{
		glfwSetWindowTitle(Handle, title);
		std::cerr << "Window Title Changed ..." << std::endl;
	}

	void Window::SetSize(int width, int height)
	{
		glfwSetWindowSize(Handle, width, height);
		std::cerr << "Window Size Updated ..." << std::endl;
	}

	int Window::GetWidth()
	{
		int width, height;
		glfwGetWindowSize(Handle, &width, &height);
		return width;
	}

	int Window::GetHeight()
	{
		int width, height;
		glfwGetWindowSize(Handle, &width, &height);
		return height;
	}

	GLFWwindow* Window::GetHandle()
	{
		return Handle;
	}

	const char* Window::GetTitle()
	{
		return glfwGetWindowTitle(Handle);
	}
}