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
#include <cstdlib>
#include <ctime>

#define INF 2147483647

#define CASE_N 3

using namespace std;

double answer1; // Store the probability of rolling 7 (100000 times) in this global variable
double answer2; // Store the probability of rolling 2 (100000 times) in this global variable
double answer3; // Store the probability of rolling 12 (100000 times) in this global variable

static const int MAX_N[CASE_N] = {1000, 10000, 100000};

inline int twice_dice()
{
    int a = rand() % 6 + 1;
    int b = rand() % 6 + 1;
    return a + b;
}

int main()
{
    srand(time(NULL));

    int point_times[CASE_N][13] = {0}; // store the point appear times (e.g. if the dice appear 3, ++point_times[x][3])

    for(size_t i = 0;i < CASE_N;++i)
        for(size_t j = 0;j < MAX_N[i];++j)
            ++point_times[i][twice_dice()];

    // print
    cout << setw(15) << "points | ";
    for(int j = 2;j <= 12;++j)
        cout << setw(6) << j;
    cout << endl;

    for(size_t i = 0;i < 82;i++)
        cout << "=";
    cout << endl;

    for(size_t i = 0;i < CASE_N;++i)
    {
        cout << setw(6) << MAX_N[i] << " times | ";
        for(int j = 2;j <= 12;++j)
            cout << setw(6) << point_times[i][j];
        cout << endl;
    }

    // store answer
    answer1 = point_times[2][7]  / MAX_N[2];
    answer2 = point_times[2][2]  / MAX_N[2];
    answer3 = point_times[2][12] / MAX_N[2];

    return 0;
}

