#pragma once

#include<iostream>
#include<vector>
#include<ctime>

//SFML
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

class object;

class op
{
    private:
    //std::vector<int> a;
    
    

    public:

    op();
    virtual ~op();

    
    void setVect(std::vector<object>* obj);
    void multiply();
    void print();

    
};
