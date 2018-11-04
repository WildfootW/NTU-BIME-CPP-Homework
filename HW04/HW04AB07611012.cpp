//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-11-04
// FILENAME : HW04AB07611012.cpp
// DESCRIPTION : Find perfect number
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */

#include <iostream>
#include <vector>
#define INF 2147483647
#define MAXN 10000

using namespace std;

int answer1; // Store the largest perfect number less than 10000 in this global variable

bool is_perfect_number(long int num);   // return true if num is perfect number

int main()
{
    vector<long int> perfect_numbers;   // store perfect numbers
    for(long int i = 1;i < MAXN;++i)
        if(is_perfect_number(i))
            perfect_numbers.push_back(i);
    cout << "perfect numbers:\n";
    for(size_t i = 0;i < perfect_numbers.size();++i)
        cout << perfect_numbers[i] << " ";
    answer1 = perfect_numbers.back();
    return 0;
}

bool
is_perfect_number(long int num)
{
    long long int factor_sum = 0;
    for(int i = 1;i < num;++i)
        if(num % i == 0)
            factor_sum += i;
    if(factor_sum == num)
        return true;
    return false;
}
