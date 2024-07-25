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

    Shader* shader;
    Shape* shape;
    Vector2D* pos;
    Vector4D* color;

    void init() override
    {
        shape = new Shape(vertices, sizeof(vertices), indices, sizeof(indices));
        shader = new Shader("simple");
        pos = new Vector2D(0, 0);
        color = new Vector4D(1, 0.5, 0, 0);
    }

    void update() override
    {
        if (Input::getMouseButtonDown(window, GLFW_MOUSE_BUTTON_LEFT))
        {
            std::cout << "X: " << mouse.getPosition(window)->x;
            std::cout << "Y: " << mouse.getPosition(window)->y << std::endl;
        }

        if (Input::getKeyDown(window, GLFW_KEY_W))
            pos->y += 0.01f;
        if (Input::getKeyDown(window, GLFW_KEY_S))
            pos->y -= 0.01f;
        if (Input::getKeyDown(window, GLFW_KEY_A))
            pos->x -= 0.01f;
        if (Input::getKeyDown(window, GLFW_KEY_D))
            pos->x += 0.01f;
    }

    void draw() override
    {
        shader->useProgram();
        shader->setUniform("position", pos);
        shader->setUniform("color", color);
        shape->draw();
    }

    void cleanUp() override
    {
        delete shape;
        delete shader;
        delete pos;
        delete color;
    }
};

int main()
{
    window = new Window(new Game(), 800, 800, "Hello, MemoEngine");
    window->run();
    delete window;

    return 0;
}
