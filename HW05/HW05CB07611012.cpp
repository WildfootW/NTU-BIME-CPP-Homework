//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-11-28
// FILENAME : HW05CB07611012.cpp
// DESCRIPTION : Magic square
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */
#include <iostream>
#include <iomanip>
#include <cstring>

#define INF 2147483647
#define MAXN 10000

#define move(T, U) ((T + border_size + U) % border_size)

using namespace std;

int answer1;    // Store the integer value of the cell at the top-left corner
int answer2;    // Store the integer value of the cell at the bottom-right corner

inline void new_position(int & x, int & y, int border_size)
{
    x = move(x, -1);
    y = move(y,  1);
    return;
}

int main()
{
    unsigned int border_size;
    cout << "Input the border size: ";
    cin >> border_size;

    int grid[border_size][border_size];
    memset(grid, 0, sizeof(grid));  // initial
    int x = 0, y = border_size / 2;
    for(int i = 0;i < border_size * border_size;++i)
    {
        if(grid[x][y] != 0)
        {
            x = move(x,  2);
            y = move(y, -1);
        }
        grid[x][y] = i + 1;
        new_position(x, y, border_size);
    }
    for(size_t i = 0;i < border_size;++i)
    {
        for(size_t j = 0;j < border_size;++j)
            cout << setw(3) << fixed << grid[i][j];
        cout << endl;
    }

    answer1 = grid[0][0];
    answer2 = grid[border_size - 1][border_size - 1];

    return 0;
}

