//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-11-07
// FILENAME : HW04CB07611012.cpp
// DESCRIPTION : GCD
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */

#include <iostream>
#include <iomanip>

#define INF 2147483647
#define MAX 20

using namespace std;

int answer1; // Store the greatest common divisor of 10 and 15 in this global variable
int answer2; // Store the greatest common divisor of 2 and 17 in this global variable
int answer3; // Store the greatest common divisor of 20 and 20 in this global variable

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    cout << "      ";
    for(int i = 1;i < MAX + 1;++i)
        cout << setw(3) << right << i;
    cout << endl;

    for(int i = 0;i < 68;++i)
        cout << "=";
    cout << endl;

    for(int i = 1;i < MAX + 1;++i)
    {
        cout << setw(3) << right << i << " | ";
        for(int j = 1;j < MAX + 1;++j)
        {
            cout << setw(3) << right << gcd(i, j);
        }
        cout << endl;
    }

    answer1 = gcd(10, 15);
    answer2 = gcd( 2, 17);
    answer3 = gcd(20, 20);
    return 0;
}

