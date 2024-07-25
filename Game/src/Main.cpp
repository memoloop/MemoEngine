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
        0, 100, 0,
        100, 100, 0,
        100, 0, 0,
        0, 0, 0
    };

    int indices[6] = {
        0, 1, 2, // first triangle
        2, 3, 0  // second triangle
    };

    Camera2D* camera;

    Shader* shader;
    Shape* shape;
    Vector2D* pos;
    Vector4D* color;

    void init() override
    {
        /*model = Matrix(1.0f);
        model = glm::translate(model, Vector3D(1.0f, 2.0f, 3.0f));

        view = glm::lookAt(Vector3D(0.0f, 0.0f, 5.0f),
            Vector3D(0.0f, 0.0f, 0.0f),
            Vector3D(0.0f, 1.0f, 0.0f));

        projection = glm::perspective(glm::radians(45.0f),
            1.0f,
            0.1f,
            100.0f);*/

        camera = new Camera2D(window, 0.0f, 0.0f, 1.0f);

        shape = new Shape(vertices, sizeof(vertices), indices, sizeof(indices));
        shader = new Shader("simple");
        pos = new Vector2D(100, 100);
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
            pos->y++;
        if (Input::getKeyDown(window, GLFW_KEY_S))
            pos->y--;
        if (Input::getKeyDown(window, GLFW_KEY_A))
            pos->x--;
        if (Input::getKeyDown(window, GLFW_KEY_D))
            pos->x++;

        if (Input::getKeyDown(window, GLFW_KEY_LEFT))
            camera->pos.x--;
        if (Input::getKeyDown(window, GLFW_KEY_RIGHT))
            camera->pos.x++;
    }

    void draw() override
    {
        camera->update();

        shader->useProgram();
        shader->setUniform("position", pos);
        shader->setUniform("color", color);
        shader->setUniform("model", camera->model);
        shader->setUniform("projection", camera->projection);
        shader->setUniform("view", camera->view);
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
