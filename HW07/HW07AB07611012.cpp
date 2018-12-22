//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-12-22
// FILENAME : HW07AB07611012.cpp
// DESCRIPTION : Program A : Streams and File I/O (50%)
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#define INF 2147483647
#define MAXN 10000

using namespace std;

int answer1;
// Store the total number of words in the words.txt file.
int answer2;
// Store the number of characters of the longest word you find.

void lowercase(string& str)
{
    for(size_t i = 0;i < str.length();++i)
    {
        if('A' <= str[i] && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
    }
}
string reverse_str(const string& str)
{
    string ret;
    for(size_t i = 0;i < str.length();++i)
        ret += str[str.length() - i - 1];
    return ret;
}

int main()
{
    ifstream infile("words.txt");
    string str;
    map<string, int> table;
    vector<string> reverse_strs;

    while(getline(infile, str))
    {
        lowercase(str);
        table[str] = str.length();
        reverse_strs.push_back(reverse_str(str));
    }
    int maximum = 0;
    string maximum_length_reverse_str;
    for(size_t i = 0;i < reverse_strs.size();++i)
    {
        if(table.find(reverse_strs[i]) != table.end())
        {
            if(maximum < table.find(reverse_strs[i])->second)
            {
                maximum = table.find(reverse_strs[i])->second;
                maximum_length_reverse_str = table.find(reverse_strs[i])->first;
            }
        }
    }
    cout << "maximum: " << maximum << " " << maximum_length_reverse_str << endl;
    answer1 = reverse_strs.size();
    answer2 = maximum;
    return 0;
}
