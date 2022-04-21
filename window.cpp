#include"window.h"

window::window()
{
    initWindow();
}

window::~window()
{
    delete windowObject;
}

void window::initWindow()
{
    videoMode.height=600;
    videoMode.width=800;
    windowObject = new sf::RenderWindow(videoMode, "Test SFML", 
                                        sf::Style::Default);
    windowObject->setFramerateLimit(60);
}

sf::RenderWindow* window::getWindow()
{
    return windowObject;
}

sf::Event &window::getEvent()
{
    return event;
}

void window::update()
{

}

void window::render()
{
    
}