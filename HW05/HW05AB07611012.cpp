//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-11-28
// FILENAME : HW05AB07611012.cpp
// DESCRIPTION : Caesar Shift Cipher Decoder
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */

#include <iostream>
#define INF 2147483647
#define MAXN 10000

using namespace std;

char answer1;   // Store the first character of the decoded sentence
char answer2;   // Store the last character of the decoded sentence

inline char shift_char(char origin, int K)
{
    while(K < 0)
    {
        K += 26;
    }
    if(origin >= 'A' && origin <= 'Z')
        return ((origin - 'A' + K) % 26) + 'A';
    return origin;
}

int main()
{
    string encrypted = "O RUBK IUSVAZKX VXUMXGSSOTM YU SAIN";
    string decrypted;
    int K_position = 6;
    cout << "decrypting \"" << encrypted << "\"...\n";
    for(size_t i = 0;i < encrypted.length();i++)
    {
        decrypted += shift_char(encrypted[i], -K_position);
    }
    cout << "done! origin string:\n";
    cout << decrypted << endl;

    answer1 = decrypted[0];
    answer2 = decrypted[decrypted.length() - 1];

    return 0;
}

