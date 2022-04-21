#include "op.h"

enum class direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STOP
};

class object
{
    private:
    sf::RectangleShape shape;
    direction dir;  //Actual Direction
    direction prev; //Previous Direction
    sf::Vector2f upLeft; //UP_LEFT


                        
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