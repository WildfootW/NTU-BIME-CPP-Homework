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
    vector<int> primes; // store all primes
    vector<pair<int, int>> twin_primes; // store twin primes
    primes.push_back(2);
    for(int i = 3;i < MAX;i++)
    {
        bool is_prime = true;
        for(unsigned int j = 0;j < primes.size() && primes[j] <= sqrt(i);j++)
        {
            if(i % primes[j] == 0) // if there are any number j can divise i, set flag to false and break
            {
                is_prime = false;
                break;
            }
        }
        if(is_prime)
        {
            if(primes.back() + 2 == i) // check if it is twin prime
                twin_primes.push_back(make_pair(primes.back(), i));
            primes.push_back(i); // record prime to vector
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

