//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-12-12
// FILENAME : HW05AB07611012.cpp
// DESCRIPTION : Bridge card game
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define INF 2147483647
#define MAXN 10000

using namespace std;

int answer1; // Store the high-card points of the first player in the final run of dealing.
int answer2; // Store the high-card points of the second player in the final run of dealing.
int answer3; // Store the high-card points of the third player in the final run of dealing.
int answer4; // Store the high-card points of the fourth player in the final run of dealing.

class game
{
    friend ostream& operator << (ostream& os, const game& e);
public:
    void shuffle_und_distribute()
    {
        for(int i = 0;i < 4;++i)
            players[i].cards.clear();
        bool dealed[52];
        memset(dealed, false, sizeof(bool) * 52);
        size_t player_ptr = 0;

        for(int i = 0;i < 52;++i)
        {
            int new_card;
            do
            {
                new_card = rand() % 52;
            }
            while(dealed[new_card]);
            dealed[new_card] = true;

            players[player_ptr].cards.push_back(card(new_card));

            ++player_ptr;
            if(player_ptr == 4)
                player_ptr = 0;
        }
    }
    class card
    {
        friend class game;
        friend class player;
        friend ostream& operator << (ostream& os, const card&);
    public:
        card(char suit, char number): _suit(suit), _number(number) {}
        explicit card(int n) {   // 0 ~ 51
            _number = card_number[n % 13];
            _suit = card_suit[n / 13];
        }

    private:
        const static char card_number[13];
        const static char card_suit[4];
        char _suit, _number;
    };
    class player
    {
    public:
        int total_point() const
        {
            int ret = 0;
            for(int i = 0; i != 13;++i)
            {
                if(cards[i]._number == 'A') ret += 4;
                if(cards[i]._number == 'K') ret += 3;
                if(cards[i]._number == 'Q') ret += 2;
                if(cards[i]._number == 'J') ret += 1;
            }
            return ret;
        }
        vector<card> cards;
    private:
    };
    player players[4];
private:
};
ostream& operator << (ostream& os, const game::card& e)
{
    return (os << e._suit << e._number);
}
ostream& operator << (ostream& os, const game& e)
{
    for(int i = 0;i < 4;++i)
    {
        os << "player " << i << ": ";
        for(int j = 0;j < 13;++j)
        {
            os << e.players[i].cards[j] << " ";
        }
        os << "point: " << e.players[i].total_point() << endl;
    }
}


const char game::card::card_number[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K'};
const char game::card::card_suit[4] = {'s', 'h', 'd', 'c'};

int main()
{
    fstream fout("CardGame.txt");
    srand(time(NULL));
    game the_game;
    for(int i = 0;i < 3;++i)
    {
        cout << "round " << i << ":" << endl;
        fout << "round " << i << ":" << endl;
        the_game.shuffle_und_distribute();
        cout << the_game;
        fout << the_game;
    }
    answer1 = the_game.players[0].total_point();
    answer2 = the_game.players[1].total_point();
    answer3 = the_game.players[2].total_point();
    answer4 = the_game.players[3].total_point();
    fout.close();
    return 0;
}

