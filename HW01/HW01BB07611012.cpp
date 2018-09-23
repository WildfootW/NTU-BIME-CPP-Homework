//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-09-22
// FILENAME : HW01BB07611012.cpp
// DESCRIPTION : Compute the average of three double
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
    double keyin_a, keyin_b, keyin_c;   // declare three double variable
    double average;                     // declare average variable
    cin >> keyin_a >> keyin_b >> keyin_c;               // input three double
    average = (keyin_a + keyin_b + keyin_c) / 3.0;      // calculate average
    cout << "The average grade is " << average << endl; // print average
    answer1 = average;  // assign average to answer1

    return 0;
}

