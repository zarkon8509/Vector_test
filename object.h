#include "op.h"

class object
{
    private:
    sf::RectangleShape shape;

    void initShape();

    public:
    object();

    sf::RectangleShape &getShape();

    //Update
    void update();

    //Render
    void render(sf::RenderTarget* target);




};