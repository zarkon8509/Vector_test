#include "op.h"

class window
{
    private:
    sf::RenderWindow* windowObject;
    sf::VideoMode videoMode;
    sf::Event event;
    

    void initWindow();
    void initShape();

    public:
    window();
    virtual ~window();

    //Update
    void update();

    //Render
    void render();
    
    //getters

    sf::RenderWindow* getWindow();
    sf::Event& getEvent();
    sf::RectangleShape& getShape();


};