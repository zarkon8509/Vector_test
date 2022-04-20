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
    shape.setOrigin((rand()%800)/2, (rand()%600)/2);
    shape.setFillColor(sf::Color::Red);
}

//Render

void object::render(sf::RenderTarget *target)
{
    target->draw(shape);
}