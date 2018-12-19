//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-12-12
// FILENAME : HW05AB07611012.cpp
// DESCRIPTION : Morse code
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */

#include <iostream>
#include <fstream>
#include <map>
#define INF 2147483647
#define MAXN 10000

using namespace std;

int answer1; // Store the total number of words in MorseCode.txt
int answer2; // Store the total number of characters (excluding comma, period, and space) in MorseCode.txt

static map<char, string> morse_code_parse;

void init()
{
    morse_code_parse['A'] = ".-";
    morse_code_parse['B'] = "-...";
    morse_code_parse['C'] = "-.-.";
    morse_code_parse['D'] = "-..";
    morse_code_parse['E'] = ".";
    morse_code_parse['F'] = "..-.";
    morse_code_parse['G'] = "--.";
    morse_code_parse['H'] = "....";
    morse_code_parse['I'] = "..";
    morse_code_parse['J'] = ".---";
    morse_code_parse['K'] = "-.-";
    morse_code_parse['L'] = ".-..";
    morse_code_parse['M'] = "--";
    morse_code_parse['N'] = "-.";
    morse_code_parse['O'] = "---";
    morse_code_parse['P'] = ".--.";
    morse_code_parse['Q'] = "--.-";
    morse_code_parse['R'] = ".-.";
    morse_code_parse['S'] = "...";
    morse_code_parse['T'] = "-";
    morse_code_parse['U'] = "..-";
    morse_code_parse['V'] = "...-";
    morse_code_parse['W'] = ".--";
    morse_code_parse['X'] = "-..-";
    morse_code_parse['Y'] = "-.--";
    morse_code_parse['Z'] = "--..";
    morse_code_parse['0'] = "-----";
    morse_code_parse['1'] = ".----";
    morse_code_parse['2'] = "..---";
    morse_code_parse['3'] = "...--";
    morse_code_parse['4'] = "....-";
    morse_code_parse['5'] = ".....";
    morse_code_parse['6'] = "-....";
    morse_code_parse['7'] = "--...";
    morse_code_parse['8'] = "---..";
    morse_code_parse['9'] = "----.";
    morse_code_parse['.'] = ".-.-.-";
    morse_code_parse[','] = "--..--";
    morse_code_parse['?'] = "..--..";
    morse_code_parse[' '] = " ";
}

int main()
{
    ifstream fin("MorseCode.txt");
    ofstream fout("MorseCode.dat");

    init();
    char ch;
    while(fin.get(ch))
    {
        if( 'a' <= ch && ch <= 'z' )
            ch = ch - 'a' + 'A';

        fout << morse_code_parse[ch] << " ";
        cout << morse_code_parse[ch] << " ";

        if( ch == ' ' || ch == '\n' )
            ++answer1;
        if( ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9') )
            ++answer2;
    }

    fin.close();
    fout.close();
    return 0;
}

