#include "object.h"

object::object()
{
    initShape();
    initVariables();
}
//Getters

sf::RectangleShape &object::getShape()
{
    return shape;
}

direction &object::getDirection()
{
    return dir;
}
void object::initVariables()
{
    up        = sf::Vector2f(0.f, -1.f);
    down      = sf::Vector2f(0.f, 1.f);
    left      = sf::Vector2f(-1.f, 0.f);
    right     = sf::Vector2f(1.f, 0.f);
    upLeft    = sf::Vector2f (-1.f , -1.f);
    upRight   = sf::Vector2f (1.f  , -1.f);
    downLeft  = sf::Vector2f (-1.f ,  1.f);
    downRight = sf::Vector2f (1.f  ,  1.f);
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
        shape.move(up);
    break;
    case direction::DOWN:
        shape.move(down);
    break;
    case direction::LEFT:
        shape.move(left);
    break;
    case direction::RIGHT:
        shape.move(right);
    break;

    //Diagonal Direction

     case direction::upLeft:
        shape.move(upLeft);
        break;
    case direction::upRight:
        shape.move(upRight);
    break;
    case direction::downLeft:
        shape.move(downLeft);
    break;
    case direction::downRight:
        shape.move(downRight);
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
        if(prev==direction::upLeft)
            dir=direction::upRight;
        else
            if(prev==direction::LEFT)
                dir=direction::RIGHT;
            else
                dir=direction::downRight;
    }

    //Up
    if(shape.getPosition().y < 0.f)
    {
        if(prev==direction::upLeft)
            dir=direction::downLeft;
        else
            if(prev==direction::UP)
                dir=direction::DOWN;
            else
                dir=direction::downRight;
    }

    //Down
    if(shape.getPosition().y + shape.getGlobalBounds().height>
        target->getSize().y)
        {
            if(prev==direction::downLeft)
                dir=direction::upLeft;
            else
                if(prev==direction::DOWN)
                    dir=direction::UP;
                else
                    dir=direction::upRight;
        }
    
    //Right
    if(shape.getPosition().x + shape.getGlobalBounds().width>
        target->getSize().x)
        {
            if(prev==direction::upRight)
                dir=direction::upLeft;
            else
                if(prev==direction::RIGHT)
                    dir=direction::LEFT;
                else
                    dir=direction::downLeft;
        }
}

//Start Movement

void object::start()
{
    dir=static_cast<direction>(rand()%
                    (static_cast<int>(direction::STOP)));
}