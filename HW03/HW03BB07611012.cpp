//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-10-17
// FILENAME : HW03BB07611012.cpp
// DESCRIPTION : Calculation of prime numbers
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */


#include <iostream>
#include <vector>
#include <cmath>
#define INF 2147483647
#define MAX 1000
//#define BONUS

using namespace std;

#ifndef BONUS
int answer1; // Store the largest prime number less than 1000 in this global variable
#else
int answer1; // First prime number of the largest pair of twin prime number less than 1000
int answer2; // Second prime number of the largest pair of twin prime number less than 1000
#endif

int main()
{
    int last_prime = -1; // store the last prime we find out
    vector<int> primes; // store all primes
    vector<pair<int, int>> twin_primes; // store twin primes
    for(int i = 2;i < MAX;i++)
    {
        bool is_prime = true;
        for(int j = 2;j < sqrt(i);j++)
        {
            if(i % j == 0) // if there are any number j can divise i, set flag to false and break
            {
                is_prime = false;
                break;
            }
        }
        if(is_prime)
        {
            primes.push_back(i); // record prime to vector
            if(last_prime + 2 == i) // check if it is twin prime
                twin_primes.push_back(make_pair(last_prime, i));
            last_prime = i; // update last_prime
        }
    }

#ifndef BONUS
    cout << "prime list: " << endl;
    for(int e:primes)
        cout << e << " ";
    cout << endl;
    answer1 = primes.back();
#else
    cout << "twin primes list: " << endl;
    for(pair<int, int> e:twin_primes)
        cout << e.first << "x" << e.second << " ";
    cout << endl;
    answer1 = twin_primes.back().first;
    answer2 = twin_primes.back().second;
#endif

    return 0;
}

