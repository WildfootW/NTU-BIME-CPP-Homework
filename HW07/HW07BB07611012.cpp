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
#include <vector>
#define INF 2147483647
#define MAXN 10000

using namespace std;

// Store the total number of persons list in the persons.txt file.
int answer1;
// Store the calculated average age.
int answer2;
// Store the calculated oldest age.
int answer3;
// Store the calculated youngest age.
int answer4;

class person
{
public:
    person() {}
    person(string first, string last, unsigned int age): _first_name(first), _last_name(last), _age(age) {}

    // set functions
    unsigned int get_age() const { return _age; }
    //string get_first_name() const { return _first_name; }
    //string get_last_name() const { return _last_name; }

    // set functions
    //void set_age(const unsigned int& age) { _age = age; }
    //void set_first_name(const string& str) { _first_name = str; }
    //void set_last_name(const string& str) { _last_name = str; }

private:
    string _first_name;
    string _last_name;
    unsigned int _age;
};

class people_list
{
public:
    people_list(): _min_age(MAXN), _max_age(0), _total_age(0) {}
    void push_back(const person& a_person)
    {
        _list.push_back(a_person);
        if(_max_age < a_person.get_age())
            _max_age = a_person.get_age();
        if(_min_age > a_person.get_age())
            _min_age = a_person.get_age();
        _total_age += a_person.get_age();
    }
    unsigned int get_max_age() const { return _max_age; }
    unsigned int get_min_age() const { return _min_age; }
    unsigned int calc_average_age() const { return _list.size() == 0 ? 0 : _total_age / _list.size(); }
    size_t size() const { return _list.size(); }
private:
    vector<person> _list;
    unsigned int _max_age;
    unsigned int _min_age;
    unsigned int _total_age;
};

int main()
{
    string first_name;
    string last_name;
    unsigned int age;
    people_list the_people_list;
    ifstream infile("person.txt");

    while( infile >> first_name >> last_name >> age )
    {
        the_people_list.push_back(person(first_name, last_name, age));
    }

    answer1 = the_people_list.size();
    cout << "max age: " << (answer3 = the_people_list.get_max_age()) << endl;
    cout << "min age: " << (answer4 = the_people_list.get_min_age()) << endl;
    cout << "ave age: " << (answer2 = the_people_list.calc_average_age()) << endl;
    return 0;
}
