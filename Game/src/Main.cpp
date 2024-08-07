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

    Sprite* sprite;
    TexturedSprite* sprite2;
    std::vector<Texture*> frames;

    Audio* audio;
    bool playing;

    void init() override
    {
        AudioManager::init();

        window->setColor(0.35f, 0.7f, 1.0f, 1.0f);

        frames = Spritesheet::create("res/images/image.png", 2, 2);

        audio = new Audio("res/audio/Inst.ogg");
        playing = audio->play();

        sprite = new Sprite(camera, 0, 0, 100, 100);
        sprite->color = { 255, 255, 0, 255 };
        sprite2 = new TexturedSprite(camera, 150, 300, 100, 100, frames[0]);
    }

    void update() override
    {
        if (Input::getMouseButtonDown(window, GLFW_MOUSE_BUTTON_LEFT))
        {
            std::cout << "X: " << mouse.getPosition(window)->x;
            std::cout << "Y: " << mouse.getPosition(window)->y << std::endl;
        }

        if (Input::getKeyDown(window, GLFW_KEY_SPACE))
        {
            playing = audio->play();
        } 
    }

    void draw() override
    {
        camera->update();

        sprite->draw();
        sprite2->draw();
    }

    void cleanUp() override
    {
        delete sprite;
        delete sprite2;

        delete audio;

        frames.clear();
        AudioManager::destroy();
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
