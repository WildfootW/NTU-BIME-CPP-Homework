//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-10-17
// FILENAME : HW03DB07611012.cpp
// DESCRIPTION : Use of selection structure and repetition structure
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */


#include <iostream>
#define INF 2147483647
#define MAX 3

using namespace std;

int answer1;
// Store the total number of rounds in this variable

enum RPS_game
{
    Rock,
    Paper,
    Scissors
};

bool contest(RPS_game& left, RPS_game& right)
{
    if(left == right)
        return false;
    if(left == Rock)
        return right == Scissors;
    else if(left == Paper)
        return right == Rock;
    else if(left == Scissors)
        return right == Paper;
}

int main()
{
    int player_win_round[2] = {0};
    char player_input[2];
    RPS_game player_figure[2];
    int count = 0;
    while(cin >> player_input[0] >> player_input[1])
    {
        count++;
        for(int i = 0;i < 2;i++)
        {
            switch(player_input[i])
            {
                case 'R':
                    player_figure[i] = Rock;
                    break;
                case 'S':
                    player_figure[i] = Scissors;
                    break;
                case 'P':
                    player_figure[i] = Paper;
                    break;
            }
        }
        if(player_figure[0] == player_figure[1]) // draw
            continue;
        else if(contest(player_figure[0], player_figure[1])) // p0 win
        {
            player_win_round[0]++;
        }
        else // p1 win
        {
            player_win_round[1]++;
        }

        if(player_win_round[0] == MAX || player_win_round[1] == MAX)
            break;
    }
    answer1 = count;
    return 0;
}


