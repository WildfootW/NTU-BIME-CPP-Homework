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
    RPS_game A = RPS_game::Rock;
    RPS_game B = RPS_game::Paper;
    if(A == B)
        cout << "draw" << endl;
    else if(contest(A, B))
        cout << "win" << endl;
    else
        cout << "lose" << endl;

    return 0;
}


