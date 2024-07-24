#include <iostream>
#include <MemoEngine.h>

Window* window;

class Game : public IGame
{
public:
	Game() {}
	~Game() {}

	Mouse mouse;

	void init() override
	{

	}

	void update() override
	{
		if (Input::getMouseButtonDown(window, GLFW_MOUSE_BUTTON_LEFT))
		{
			std::cout << "X: " << mouse.getPosition(window)->x;
			std::cout << "Y: " << mouse.getPosition(window)->y << std::endl;
		}
	}

	void draw() override
	{
		glBegin(GL_QUADS);
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glVertex2f(-0.5f, -0.5f);	// bottom-left
		glVertex2f(0.5f, -0.5f);	// bottom-right
		glVertex2f(0.5f, 0.5f);		// top-right
		glVertex2f(-0.5f, 0.5f);	// top-left
		glEnd();
	}

	void cleanUp() override
	{

	}
};

int main()
{
	window = new Window(new Game(), 800, 800, "Hello, MemoEngine");
	window->run();
	delete window;

	return 0;
}