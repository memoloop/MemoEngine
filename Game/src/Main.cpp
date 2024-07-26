#include <iostream>
#include "MemoEngine.h"

Window* window;
Camera2D* camera;

class Game : public IGame
{
public:
    Game() {}
    ~Game() {}

    Mouse mouse;

    float vertices[12] = {
        0, 0, 0,
        100, 0, 0,
        100, 100, 0,
        0, 100, 0
    };

    float textures[8] = {
        0, 0,
        1, 0,
        1, 1,
        0, 1
    };

    int indices[6] = {
        0, 1, 2,
        2, 3, 0,
    };

    Shader* shader;
    Shape* shape;
    Vector2D* pos;
    Vector4D* color;
    Texture* texture;

    void init() override
    {
        window->setColor(0.35f, 0.7f, 1.0f, 1.0f);

        shape = new Shape(vertices, sizeof(vertices), textures, sizeof(textures), indices, sizeof(indices));
        shader = new Shader("texture");
        pos = new Vector2D(0, 0);
        color = new Vector4D(1, 0.5, 0, 1.0);
        texture = new Texture("res/images/mimmo.png");
    }

    void update() override
    {
        if (Input::getMouseButtonDown(window, GLFW_MOUSE_BUTTON_LEFT))
        {
            std::cout << "X: " << mouse.getPosition(window)->x;
            std::cout << "Y: " << mouse.getPosition(window)->y << std::endl;
        }

        if (Input::getKeyDown(window, GLFW_KEY_W))
            pos->y--;
        if (Input::getKeyDown(window, GLFW_KEY_S))
            pos->y++;
        if (Input::getKeyDown(window, GLFW_KEY_A))
            pos->x--;
        if (Input::getKeyDown(window, GLFW_KEY_D))
            pos->x++;

        if (Input::getKeyDown(window, GLFW_KEY_LEFT))
            camera->pos.x--;
        if (Input::getKeyDown(window, GLFW_KEY_RIGHT))
            camera->pos.x++;

        if (Input::getKeyDown(window, GLFW_KEY_SPACE)) 
        {
            texture = new Texture("res/images/face.png");
        }
    }

    void draw() override
    {
        camera->update();

        shader->useProgram();
        texture->bind(0);
        shader->setUniform("sampler", 0);
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
        delete texture;
    }
};

int main()
{
    window = new Window(new Game(), 800, 800, "Hello, MemoEngine");
    camera = new Camera2D(window, 0.0f, 0.0f, 1.0f);
    window->run();
    delete window;
    delete camera;

    return 0;
}
