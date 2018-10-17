//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-10-17
// FILENAME : HW03AB07611012.cpp
// DESCRIPTION : Calculation of pi
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */


#include <iostream>
#define INF 2147483647

using namespace std;

double answer1; // Store the value of pi(k = 100000) you calculated in this global variable before exiting your program

// calc the right side of Leibniz series
double Leibniz_right(int k_f)
{
    double ret = 0;
    for(int i = 0;i < k_f;i++)
    {
        if(i % 2)   // (-1) ^ i is -1 if i is a odd number
            ret -= 1 / (double)(2 * i + 1);
        else
            ret += 1 / (double)(2 * i + 1);
    }
    return ret;
}

int main()
{
    const double fixed_pi = 3.141592653589793238463;
    const int k_f[3] = {1000, 10000, 100000};
    cout.precision(20);
    for(int i = 0;i < 3;i++)
    {
        // calc pi
        double pi = Leibniz_right(k_f[i]) * 4;

        // print result and error
        cout << "The pi calc by k from 0 to " << k_f[i] << ":" << endl;
        cout << "pi: " << fixed << pi << endl;
        cout << "error: " << pi - fixed_pi << endl << endl;

        // store answer
        if(k_f[i] == 100000)
            answer1 = pi;
    }
    return 0;
}

