#include "object.h"

object::object()
{
    initShape();
}

sf::RectangleShape &object::getShape()
{
    return shape;
}

void object::initShape()
{
    shape.setSize(sf::Vector2f(50.f, 50.f));
    shape.setPosition(static_cast<float>(rand()%800)/2,
                      static_cast<float>(rand()%600)/2);
    shape.setFillColor(sf::Color::Red);
    dir = direction::STOP;
}

//Update

void object::update()
{
    moveObj();
}


//Render

void object::render(sf::RenderTarget *target)
{
    target->draw(shape);
}

//Move

void object::moveObj()
{
    switch (dir)
    {
    case direction::UP:
    if(prev==direction::LEFT)
        shape.move(sf::Vector2f(1.f, -1.f));
    else if(prev==direction::RIGHT)
        shape.move(sf::Vector2f(-1.f, -1.f));
    break;
    case direction::DOWN:
    if(prev==direction::LEFT)
        shape.move(sf::Vector2f(1.f, 1.f));
    else if(prev==direction::RIGHT)
        shape.move(sf::Vector2f(-1.f, 1.f));
    break;
    case direction::LEFT:
    if(prev==direction::UP)
        shape.move(sf::Vector2f(-1.f, -1.f));
    else if(prev==direction::DOWN)
        shape.move(sf::Vector2f(-1.f, 1.f));
    break;
    case direction::RIGHT:
    if(prev==direction::UP)
        shape.move(sf::Vector2f(1.f, 1.f));
    else if(prev==direction::DOWN)
        shape.move(sf::Vector2f(1.f, -1.f));
    break;
    default:
        break;
    }
}

//Collisions Detection

void object::checkCollision(sf::RenderWindow* target)
{
    //Window Border Collision

    prev = dir;
    //Left
    if(shape.getPosition().x < 0.f)
    {
        dir = direction::RIGHT; 
        //shape.setPosition(sf::Vector2f(0.f, shape.getPosition().y));
    }

    //Up
    if(shape.getPosition().y < 0.f)
    {
        dir = direction::DOWN;
        //shape.setPosition(sf::Vector2f(shape.getPosition().x,0.f));
    }

    //Down
    if(shape.getPosition().y + shape.getGlobalBounds().height>
        target->getSize().y)
        {
            dir = direction::UP;
            //shape.setPosition(sf::Vector2f(shape.getPosition().x, 0.f));
        }
    
    //Right
    if(shape.getPosition().x + shape.getGlobalBounds().width>
        target->getSize().x)
        {
            dir = direction::LEFT;
            //shape.setPosition(sf::Vector2f(0.f, shape.getPosition().y));
        }
}

//Start Movement

void object::start()
{
    dir=static_cast<direction>(rand()%
                    (static_cast<int>(direction::STOP)));
}