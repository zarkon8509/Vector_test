#include "op.h"
#include "window.h"
#include "object.h"

int main()

{
    op op;
    window win;
    std::vector<object> obj;
    srand(time((nullptr)));

    std::cout<<"\n Insert Quantity: ";
    int choice;
    std::cin>> choice;
    for (size_t i = 0; i < choice; i++)
    {
        op.setVect(&obj);
    }
    //op.multiply();
    //op.print();
    while(win.getWindow()->isOpen())
    {
        while (win.getWindow()->pollEvent(win.getEvent()))
        {
            switch (win.getEvent().key.code)
            {
            case sf::Keyboard::Escape:
                win.getWindow()->close();
                break;
            default:
                break;
            }
            if(win.getEvent().type == sf::Event::Closed)
                win.getWindow()->close();

            win.getWindow()->clear();
            for(auto& o:obj)
                o.render(win.getWindow());
            win.getWindow()->display();
        }
        
    }    
    return 0;
}

