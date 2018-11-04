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
#include <cstdlib>
#include <ctime>
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

RPS_game convert_char_rps(char input = 'N')
{
    if(input == 'N')
    {
        switch(rand() % 3)
        {
            case 0:
                input = 'R';
                break;
            case 1:
                input = 'P';
                break;
            case 2:
                input = 'S';
                break;
        }
    }
    switch(input)
    {
        case 'R':
            return Rock;
        case 'S':
            return Scissors;
        case 'P':
            return Paper;
    }
}

int main()
{
    srand (time(NULL));
    int player_win_round = 0, computer_win_round = 0;
    char player_input;
    int count = 1;
    cout << "Round " << count << "!\n";
    cout << "input your choice: ";
    while(cin >> player_input)
    {
        RPS_game player_figure, computer_figure;
        count++;
        player_figure = convert_char_rps(player_input);
        computer_figure = convert_char_rps();
        if(player_figure == computer_figure) // draw
        {
            cout << "Draw!\n";
        }
        else if(contest(player_figure, computer_figure)) // player win
        {
            cout << "Player win!\n";
            player_win_round++;
        }
        else // computer win
        {
            cout << "Computer win!\n";
            computer_win_round++;
        }

        if(player_win_round == MAX || computer_win_round == MAX)
            break;
        cout << "========================\n";
        cout << "Round " << count << "!\n";
        cout << "input your choice: ";
    }
    answer1 = count;
    return 0;
}


