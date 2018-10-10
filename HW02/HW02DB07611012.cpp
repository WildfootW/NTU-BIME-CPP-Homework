//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-10-10
// FILENAME : HW02DB07611012.cpp
// DESCRIPTION : calculate the total value of blackjack game
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

int answer1; // Store the total value of the hand
int answer2; // Store the sum of the three cards

int main()
{
    int cards[3];
    int ace_num = 0;
    int sum = 0, blackjack_sum = 0;
    cout << "please input three cards(a 1 corresponding to an ace, a 2 corresponding to a two, and so on):\n";
    for(int i = 0;i < 3;i++)
    {
        cin >> cards[i];

        if(cards[i] < 1 || cards[i] > 13) // check if card valid
        {
            cerr << "main(): card point must between 1 and 13";
            return 1;
        }

        if(cards[i] == 1) // count the number of ace
            ace_num++;

        sum += cards[i]; // calc the sum of three cards

        if(cards[i] > 10) // calc J, Q, K as 10 points
            blackjack_sum += 10;
        else
            blackjack_sum += cards[i];
    }
    while(blackjack_sum + 10 <= 21 && ace_num > 0) // calc ace as 11 if it will not exceed 21.
    {
        blackjack_sum += 10;
        ace_num--;
    }

    cout << "total value of the hand: " << blackjack_sum << "\n";
    cout << "the sum of the three cards: " << sum << "\n";
    answer1 = blackjack_sum;
    answer2 = sum;

    return 0;
}

