#include <iostream>
#include "MemoEngine.h"

Window* window;

class Game : public IGame
{
public:
    Game() {}
    ~Game() {}

    Mouse mouse;

    float vertices[12] = {
        -0.5f, -0.5f, 0.0f, // bottom left
        0.5f, -0.5f, 0.0f,  // bottom right
        0.5f, 0.5f, 0.0f,   // top right
        -0.5f, 0.5f, 0.0f   // top left
    };

    int indices[6] = {
        0, 1, 2, // first triangle
        2, 3, 0  // second triangle
    };

    Shape* shape;

    void init() override
    {
        shape = new Shape(vertices, sizeof(vertices), indices, sizeof(indices));
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
        shape->draw();
    }

    void cleanUp() override
    {
        delete shape;
    }
};

int main()
{
    window = new Window(new Game(), 800, 800, "Hello, MemoEngine");
    window->run();
    delete window;

    return 0;
}
