//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-11-28
// FILENAME : HW05DB07611012.cpp
// DESCRIPTION : Caesar Shift Cipher Decoder
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */

#include <iostream>
#include <iomanip>
#define INF 2147483647
#define MAXN 10000

using namespace std;

int answer1;
// The value of K to decode the above encrypted message.
char answer2;
// Store the first character of the decoded sentence
char answer3;
// Store the last character of the decoded sentence

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
    string encrypted = "GWC IZM ZMITTG I PIZL EWZSQVO ABCLMVB";
    string decrypted;
    for(int j = 0;j < 26;++j)
    {
        string test_decrypted;
        for(size_t i = 0;i < encrypted.length();++i)
        {
            test_decrypted += shift_char(encrypted[i], -j);
        }
        cout << "Shift " << setw(2) << j << " : " << test_decrypted << endl;
        if(j == 8)
            decrypted = test_decrypted;
    }
    cout << "Answer: K = 8, string: ";
    cout << decrypted << endl;

    answer1 = 8;
    answer2 = decrypted[0];
    answer3 = decrypted[decrypted.length() - 1];

    return 0;
}

/*
Shift  0 : GWC IZM ZMITTG I PIZL EWZSQVO ABCLMVB
Shift  1 : FVB HYL YLHSSF H OHYK DVYRPUN ZABKLUA
Shift  2 : EUA GXK XKGRRE G NGXJ CUXQOTM YZAJKTZ
Shift  3 : DTZ FWJ WJFQQD F MFWI BTWPNSL XYZIJSY
Shift  4 : CSY EVI VIEPPC E LEVH ASVOMRK WXYHIRX
Shift  5 : BRX DUH UHDOOB D KDUG ZRUNLQJ VWXGHQW
Shift  6 : AQW CTG TGCNNA C JCTF YQTMKPI UVWFGPV
Shift  7 : ZPV BSF SFBMMZ B IBSE XPSLJOH TUVEFOU
Shift  8 : YOU ARE REALLY A HARD WORKING STUDENT
Shift  9 : XNT ZQD QDZKKX Z GZQC VNQJHMF RSTCDMS
Shift 10 : WMS YPC PCYJJW Y FYPB UMPIGLE QRSBCLR
Shift 11 : VLR XOB OBXIIV X EXOA TLOHFKD PQRABKQ
Shift 12 : UKQ WNA NAWHHU W DWNZ SKNGEJC OPQZAJP
Shift 13 : TJP VMZ MZVGGT V CVMY RJMFDIB NOPYZIO
Shift 14 : SIO ULY LYUFFS U BULX QILECHA MNOXYHN
Shift 15 : RHN TKX KXTEER T ATKW PHKDBGZ LMNWXGM
Shift 16 : QGM SJW JWSDDQ S ZSJV OGJCAFY KLMVWFL
Shift 17 : PFL RIV IVRCCP R YRIU NFIBZEX JKLUVEK
Shift 18 : OEK QHU HUQBBO Q XQHT MEHAYDW IJKTUDJ
Shift 19 : NDJ PGT GTPAAN P WPGS LDGZXCV HIJSTCI
Shift 20 : MCI OFS FSOZZM O VOFR KCFYWBU GHIRSBH
Shift 21 : LBH NER ERNYYL N UNEQ JBEXVAT FGHQRAG
Shift 22 : KAG MDQ DQMXXK M TMDP IADWUZS EFGPQZF
Shift 23 : JZF LCP CPLWWJ L SLCO HZCVTYR DEFOPYE
Shift 24 : IYE KBO BOKVVI K RKBN GYBUSXQ CDENOXD
Shift 25 : HXD JAN ANJUUH J QJAM FXATRWP BCDMNWC
*/

