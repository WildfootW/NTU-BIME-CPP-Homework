//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-10-10
// FILENAME : HW02CB07611012.cpp
// DESCRIPTION : Solving quadratic equation (ax^2 + bx + c = 0)
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */


#include <iostream>
#include <cmath>
#define INF 2147483647

using namespace std;

double answer1; // Store the value of the discriminant b2 − 4ac

int main()
{
    double constants_a, constants_b, constants_c;
    cout << "please input three number that repersent constant number a, b, c for \"ax^2 + bx + c = 0\":\n";
    cin >> constants_a >> constants_b >> constants_c;

    if(constants_a == 0) // check if constants_a is zero
    {
        cerr << "main(): a must be a non-zero number";
        return 1;
    }

    double discriminant = constants_b * constants_b - 4 * constants_a * constants_c; // calc the discriminant and store to discriminant
    if(discriminant < 0) // exit and cerr the discriminant value
    {
        cerr << "main(): the discriminanlt (" << discriminant << ") is less than 0";
        return 1;
    }
    if(discriminant == 0)
    {
        cout << "The root is " << (-constants_b) / (2 * constants_a) << " and identical.\n";
    }
    else
    {
        cout << "The roots are " << ((-constants_b) + sqrt(discriminant)) / (2 * constants_a) << " and " << ((-constants_b) - sqrt(discriminant)) / (2 * constants_a) << ".\n";
    }
    answer1 = discriminant;
    return 0;
}

