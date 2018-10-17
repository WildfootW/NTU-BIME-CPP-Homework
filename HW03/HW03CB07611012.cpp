//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-10-17
// FILENAME : HW03CB07611012.cpp
// DESCRIPTION : Use of selection structure and repetition structure
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */


#include <iostream>
#include <cstring>
#include <cmath>
#define INF 2147483647
#define MAX 1000

using namespace std;

int answer1; // The largest happy number less than 1000

static int calc_special_number(int); // return the number by the sum of the squares of its digits

int main()
{
    cout << "happy number list: " << endl;
    for(int i = 0;i < MAX;i++)
    {
        bool visited[MAX] = {false}; // recored if visit to avoid infinite loop
        int test_num = i;
        while(test_num != 1) // break loop if i is a happy number
        {
            if(visited[test_num]) // break if it is a infinite loop
                break;
            visited[test_num] = true;
            test_num = calc_special_number(test_num);
        }
        if(test_num == 1) // happy number
        {
            answer1 = i;
            cout << i << " ";
        }
    }
    return 0;
}

// return the number by the sum of the squares of its digits
static int calc_special_number(int n)
{
    int ret = 0;
    string s(to_string(n));
    for(int i = 0;i < s.length();i++)
        ret += pow(int(s[i]) - '0', 2);
    return ret;
}
