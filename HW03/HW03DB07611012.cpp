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

enum class RPS_game
{
    Rock,
    Paper,
    Scissors
};

bool contest(RPS_game& left, RPS_game& right)
{
    if(left == right)
        return false;
    if(left == RPS_game::Rock)
        return right == RPS_game::Scissors;
    else if(left == RPS_game::Paper)
        return right == RPS_game::Rock;
    else if(left == RPS_game::Scissors)
        return right == RPS_game::Paper;
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
                    player_figure[i] = RPS_game::Rock;
                    break;
                case 'S':
                    player_figure[i] = RPS_game::Scissors;
                    break;
                case 'P':
                    player_figure[i] = RPS_game::Paper;
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


