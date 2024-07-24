#include <iostream>
#include <MemoEngine.h>

Window* window;

class Game : public IGame
{
public:
	Game() {}
	~Game() {}

	void init() override
	{
		
	}

	void update() override
	{
		
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