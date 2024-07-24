#include "pch.h"
#include "MemoWindow.h"

MEMOENGINE_API Window::Window(IGame* game, int width, int height, std::string title)
{
	this->game = game;
	this->width = width;
	this->height = height;
	this->title = title;

	// Initialize GLFW
	if (!glfwInit()) 
	{
		throw new std::exception("Unable to initialize GLFW3");
	}
#ifdef _DEBUG
	else 
	{
		std::cout << "GLFW initialized with success!" << std::endl;
	}
#endif // _DEBUG

	// Use OpenGL 3.3 Core profile
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/

	// Create a window
	id = glfwCreateWindow(this->width, this->height, this->title.c_str(), nullptr, nullptr);
	if (id == nullptr) 
	{
		glfwTerminate();
		throw new std::exception("Unable to create window!");
	}
#ifdef _DEBUG
	else 
	{
		std::cout << "Window created with success!" << std::endl;
	}
#endif // _DEBUG

	// Make OpenGL Context Current
	glfwMakeContextCurrent(id);

	// Center the window on monitor
	const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(id, (videoMode->width - width) / 2, (videoMode->height - height) / 2);

	// Initialize GLEW
	GLenum eResult = glewInit();
	if (eResult != GLEW_OK)
	{
		glfwDestroyWindow(id);
		glfwTerminate();
		throw new std::exception("Unable to initialize GLEW32!");
	}
#ifdef _DEBUG
	else 
	{
		std::cout << "GLEW32 initialized with success!" << std::endl;
		std::cout << "You can use OpenGL functions now!" << std::endl;
	}
#endif // _DEBUG
}

MEMOENGINE_API Window::~Window()
{
	game->cleanUp();
	delete game;
	glfwDestroyWindow(id);
	glfwTerminate();
}

MEMOENGINE_API void Window::run()
{
	game->init();

	// Game loop
	while (!glfwWindowShouldClose(id))
	{
		// Take events
		glfwPollEvents();

		game->update();

		// Clean up the context
		glClear(GL_COLOR_BUFFER_BIT);

		game->draw();

		// Update the context
		glfwSwapBuffers(id);
	}
}

MEMOENGINE_API void Window::setWidth(int width) 
{ 
	this->width = width; 
	glfwSetWindowSize(id, this->width, height);
}

MEMOENGINE_API int Window::getWidth() { return width; }

MEMOENGINE_API void Window::setHeight(int height) 
{
	this->height = height; 
	glfwSetWindowSize(id, width, this->height);
}

MEMOENGINE_API int Window::getHeight() { return height; }

MEMOENGINE_API void Window::setTitle(std::string title) 
{
	this->title = title; 
	glfwSetWindowTitle(id, this->title.c_str());
}

MEMOENGINE_API std::string Window::getTitle() { return title; }

MEMOENGINE_API GLFWwindow* Window::getID() { return id; }