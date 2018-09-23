//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-09-22
// FILENAME : HW01CB07611012.cpp
// DESCRIPTION : compute the speed
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */


#include <iostream>

using namespace std;

double answer1; // store variable in global allow web-cat check

int main()
{
    double speed, fe, fr;

    fe = 2e10;          // initialize the fe
    fr = 2.00000035e10; // initialize the fr

    speed = 6.685e8 * (fr - fe) / (fr + fe);    // calculate and assign to speed
    cout << "The speed is " << speed << " miles/hour " << endl; // print to stdout
    answer1 = speed;

    return 0;
}

