//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-11-04
// FILENAME : HW04BB07611012.cpp
// DESCRIPTION : Data processing and sorting
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147483647

using namespace std;

int answer1; // Store the part number which is highest in stock quantity
int answer2; // Store the part number which is lowest in stock quantity

class item
{
public:
    item(){};
    item(int no, int quantity):_part_no(no), _quantity(quantity){}
    ~item(){};
    int& no(){ return _part_no; }
    const int& no() const { return _part_no; }
    int& quantity(){ return _quantity; }
    const int& quantity() const { return _quantity; }

    friend ostream& operator << (ostream&, const item&);
private:
    int _part_no;
    int _quantity;
};

ostream& operator << (ostream& os, const item& arg)
{
    os << "\"" << arg._part_no << "\" : " << arg._quantity;
    return os;
}

// quantity decreasing order (functional object)
struct item_sort_quantity
{
    bool operator () (const item& lhs, const item& rhs) const
    {
        return lhs.quantity() > rhs.quantity();
    }
};
// item part no order (functional object)
struct item_sort_no
{
    bool operator () (const item& lhs, const item& rhs) const
    {
        return lhs.no() < rhs.no();
    }
};

int main()
{
    vector<item> items;
    // add item into vector
    items.push_back(item(1001,  62));
    items.push_back(item( 949,  85));
    items.push_back(item(1050,  33));
    items.push_back(item(1200,  23));
    items.push_back(item( 867, 125));
    items.push_back(item( 346,  59));
    items.push_back(item(1025, 105));

    cout << "Decreasing quanntity order: \n";
    sort(items.begin(), items.end(), item_sort_quantity());
    for(size_t i = 0;i < items.size();++i)
        cout << items[i] << endl;
    cout << endl;

    // store answers
    answer1 = items.front().no();
    answer2 = items.back().no();

    cout << "Part number order: \n";
    sort(items.begin(), items.end(), item_sort_no());
    for(size_t i = 0;i < items.size();++i)
        cout << items[i] << endl;
    return 0;
}

