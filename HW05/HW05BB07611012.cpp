//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-11-28
// FILENAME : HW05BB07611012.cpp
// DESCRIPTION : Game of life
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

//#define DEBUG

using namespace std;

int answer1;    // Store the total number of live cells of the first generation
int answer2;    // Store the total number of live cells of the second generation
int answer3;    // Store the total number of live cells of the third generation

class coordinate
{
public:
    coordinate(int x, int y): x(x), y(y) {};
    ~coordinate() {};
    int x, y;
};
class Conway
{
private:
    bool** grid;
    unsigned int size;
    int count_around_alive(coordinate position) const
    {
        int count = 0;
        int x = position.x;
        int y = position.y;
        if(the_grid(x - 1, y - 1)) ++count;
        if(the_grid(x - 1, y    )) ++count;
        if(the_grid(x - 1, y + 1)) ++count;
        if(the_grid(x    , y - 1)) ++count;
        if(the_grid(x    , y + 1)) ++count;
        if(the_grid(x + 1, y - 1)) ++count;
        if(the_grid(x + 1, y    )) ++count;
        if(the_grid(x + 1, y + 1)) ++count;
        return count;
    }
    bool is_alive(coordinate position) const
    {
        int around_alive = count_around_alive(position);
        if(the_grid(position))  // alive
        {
            if(around_alive == 2 || around_alive == 3)
                return true;
        }
        else                    // dead
        {
            if(around_alive == 3)
                return true;
        }
        return false;
    }
public:
    Conway(unsigned int size, vector<coordinate> positions): size(size)
    {
        grid = new bool*[size + 2];
        for(size_t i = 0;i < size + 2;++i)
            grid[i] = new bool[size + 2];

        for(size_t i = 0;i < size + 2;++i)
            for(size_t j = 0;j < size + 2;++j)
                the_grid(i, j) = false;

        for(size_t i = 0;i < positions.size();++i)
            the_grid(positions[i]) = true;
    }
    ~Conway()
    {
        for(size_t i = 0;i < size + 2;i++)
            delete [] grid[i];
        delete [] grid;
    }
    void print() const
    {
        for(size_t i = 1;i <= size;++i)
        {
            for(size_t j = 1;j <= size;++j)
            {
                if(grid[i][j])
                    cout << "O ";
                else
                    cout << "X ";
            }
            cout << endl;
        }
    }
    void update_generate()
    {
        bool temp[size + 2][size + 2];

#ifdef DEBUG
        for(size_t i = 1;i <= size;++i)
        {
            for(size_t j = 1;j <= size;++j)
                cout << count_around_alive(coordinate((int)i, (int)j)) << " ";
            cout << endl;
        }
#endif
        for(size_t i = 1;i <= size;++i)
            for(size_t j = 1;j <= size;++j)
                temp[i][j] = is_alive(coordinate(i, j));

        for(size_t i = 1;i <= size;++i)
            for(size_t j = 1;j <= size;++j)
                grid[i][j] = temp[i][j];
    }
    bool& the_grid(coordinate position) const
    {
        return grid[position.x][position.y];
    }
    bool& the_grid(int x, int y) const
    {
        return grid[x][y];
    }
    int lives()
    {
        int count = 0;
        for(size_t i = 1;i <= size;++i)
            for(size_t j = 1;j <= size;++j)
                if(the_grid(i, j))
                    ++count;
        return count;
    }
};

int main()
{
    vector<coordinate> mypositions;
    mypositions.push_back(coordinate( 9,  9));
    mypositions.push_back(coordinate(12,  9));
    mypositions.push_back(coordinate(10, 10));
    mypositions.push_back(coordinate(11, 10));
    mypositions.push_back(coordinate( 9, 11));
    mypositions.push_back(coordinate(12, 11));

    Conway myconway(20, mypositions);
    for(int i = 0;i < 3;++i)
    {
        myconway.print();
        cout << endl;

        if(i == 0)
            answer1 = myconway.lives();
        if(i == 1)
            answer2 = myconway.lives();
        if(i == 2)
            answer3 = myconway.lives();

        myconway.update_generate();
    }

    return 0;
}

