//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-10-10
// FILENAME : HW02BB07611012.cpp
// DESCRIPTION : Bowling score calculation
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

int answer1; // Store the score of the three throws

int main()
{
    int scores[3], final_score = 0;
    cout << "please key in three integer that represent the score you get in this bowling game: ";
    for(int i = 0;i < 3;i++)
    {
        cin >> scores[i];
        if(scores[i] > 10 || scores[i] < 0)  // exit and throw error when a point of a throw is invalid
        {
            cerr << "main(): A throw must be in the range of 0 through 10 pins\n";
            return 1;
        }
    }

    if(scores[0] == 10) // the situation while one get a strike in the first throw
        final_score = scores[0] + scores[1] + scores[2];
    else if(scores[0] + scores[1] == 10) // the situation when the second throw knocks down the remainder of the 10 pins
        final_score = scores[0] + scores[1] + scores[2];
    else // didn't get a strike neither a apre
    {
        if(scores[0] + scores[1] > 10)  // exit and throw error while the total of the first two throws is more than 10, except when the first throw is a strike.
        {
            cerr << "main(): The total of the first two throws must be less than or equal to 10 while the first throw is not a strike\n";
            return 1;
        }
        final_score = scores[0] + scores[1];
    }
    cout << "The final bowling score is " << final_score << " points!\n";
    answer1 = final_score;

    return 0;
}

