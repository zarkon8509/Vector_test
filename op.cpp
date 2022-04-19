#include "op.h"

op::op()
{

}

void op::setVect(int i)
{
    a.push_back(i);
}

void op::multiply()
{
    for(auto& element:a)
        element*=element;
}

void op::print()
{
    std::cout<<"\n";
    for(auto& element:a)
        std::cout<<" "<<element;
}