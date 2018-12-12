//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-12-12
// FILENAME : HW05AB07611012.cpp
// DESCRIPTION : Pangram Checker
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */

#include <iostream>
#include <fstream>
#include <cstring>
#define INF 2147483647
#define MAXN 10000

using namespace std;

int answer1; // Store the total number of sentences which is NOT a pangram in the file.
int answer2; // Store the total number of sentences which is a pangram in the file.

bool PangramCheck(const string& str)
{
    bool used[26];
    memset(used, false, sizeof(used));

    for(size_t i = 0;i < str.length();++i)
    {
        char ch = toupper(str[i]);
        if('A' <= ch && ch <= 'Z')
            used[ch - 'A'] = true;
    }
    for(size_t i = 0;i < 26;++i)
        if(used[i] == false)
            return false;
    return true;
}

int main()
{
    ifstream fin("PangramList.txt");
    string s;
    while(getline(fin, s))
    {
        if(PangramCheck(s))
            ++answer2;
        else
            ++answer1;
    }

    cout << "Total number of sentences which is Not a pangram: " << answer1 << endl;
    cout << "Total number of sentences which is a pangram: " << answer2 << endl;
    fin.close();
    return 0;
}
