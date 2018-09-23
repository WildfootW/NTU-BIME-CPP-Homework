//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-09-22
// FILENAME : HW01DB07611012.cpp
// DESCRIPTION : calculate the increase length when a force applied to a metal slab
//================================================================
/*
 * Version 1.2
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */


#include <iostream>

using namespace std;

// store variable in global allow web-cat check
double answer1; // calculated increase in length for the aluminum slab
double answer2; // calculated increase in length for the copper slab

static const double kilo = 1000;    // declare kilo(10 ^ 3) as a const variable

class slab  // defined slab data structure
{
public:
    slab(){}    // constructor
    slab(double length, double width, double depth, double elasticity): length(length), width(width), depth(depth), elasticity(elasticity){}
    ~slab(){}   // destructor
    double calc_increase_length(double force)   // function that return increase length with a parameter force
    {
        return (force * kilo * length) / (width * depth * elasticity);
    }
protected:
    double length, width, depth;    // in millimeter
    double elasticity;              // metal's modulus of elasticity (N / (mm ^ 2))
};

int main()
{
    // The increase in length of a rectangular slab of metal that’s fixed at one end and pulled by a force at its other end is given by this formula: I = F * k * l / ( w * d * epsilon )

    slab aluminum_slab(3000, 40, 2, 68950);  // declare aluminum slab
    slab copper_slab(3000, 40, 2, 110000);   // declare copper slab
    answer1 = aluminum_slab.calc_increase_length(4);    // assign result of increase length to answer(global variable)
    answer2 = copper_slab.calc_increase_length(4);

    return 0;
}

