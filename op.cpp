#include "op.h"
#include "object.h"
#include <vector>

op::op()
{
    
}

op::~op()
{
    
}


void op::setVect(std::vector<object>* obj)
{
    object a;
    obj->push_back(a);
}

/*void op::multiply()
{
    for(auto& element:a)
        element*=element;
}*/

/*void op::print()
{
    std::cout<<"\n";
    for(auto& element:a)
        std::cout<<" "<<element;
}*/

