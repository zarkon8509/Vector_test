#include "op.h"

enum class direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    upLeft,
    upRight,
    downLeft,
    downRight,
    STOP
};

class object
{
    private:
    sf::RectangleShape shape;
    direction dir;          //Actual Direction
    direction prev;         //Previous Direction
    sf::Vector2f up;
    sf::Vector2f down;
    sf::Vector2f left;
    sf::Vector2f right;
    sf::Vector2f upLeft;    //UP_LEFT
    sf::Vector2f upRight;   //UP_RIGHT
    sf::Vector2f downLeft;  //DOWN_LEFT
    sf::Vector2f downRight; //DOWN_RIGHT

                        
    void initShape();
    void initVariables();
    

    public:
    object();

    sf::RectangleShape &getShape();

    //Update
    void update();

    //Render
    void render(sf::RenderTarget* target);

    //Function
    void start();
    void moveObj();
    void checkCollision(sf::RenderWindow* target);


};