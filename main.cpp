#include "op.h"

int main()

{
    op op;

    std::cout<<"\n Insert Quantity: ";
    int choice;
    std::cin>> choice;
    for (size_t i = 0; i < choice; i++)
    {
        op.setVect(i);
    }
    op.multiply();
    op.print();
    
    return 0;
}