//================================================================
// PROGRAMMER : Shen yu-che
// DATE : 2018-10-03
// FILENAME : HW02AB07611012.cpp
// DESCRIPTION : Simple arithmetic calculation
//================================================================
/*
 * Version 1.0
 * Author: WildfootW
 * GitHub: github.com/WildfootW/NTU-BIME-CPP-Homework [private]
 * Copyright (C) 2018 WildfootW All rights reserved.
 */


#include <iostream>
#define INT_NUM 3
#define INF 2147483647

using namespace std;

int answer1; // Store the sum of the three input integers
int answer2; // Store the smallest number of the three input integers
int answer3; // Store the largest number of the three input integers

int main()
{
    int input_number[INT_NUM] = {0};    // declare array to store input interger
    int sum = 0;                        // declare sum variable to store the sum of input intergers
    int product = 1;                    // declare product variable to store the product of input intergers
    int max_num = -INF, min_num = INF;  // declare max and min variable
    cout << "Input three different integers: ";
    for(int i = 0;i < INT_NUM;i++)      // a for loop that may run as mamy time as INT_NUM
    {
        cin >> input_number[i];         // save input to array
        sum += input_number[i];         // assign input plus sum to sum variable;
        product *= input_number[i];     // assign input multiply product to Product
        max_num = max(max_num, input_number[i]);    // update max_num if input is bigger than max_num
        min_num = min(min_num, input_number[i]);    // update min_num if input is bigger than min_num
    }
    cout << "Sum is " << (answer1 = sum) << endl;                   // print sum and assign to answer1
    cout << "Average is " << sum / (double)INT_NUM << endl;         // calc the average of input and change type to double
    cout << "Product is " << product << endl;                       // print product
    cout << "Smallest number is " << (answer2 = min_num) << endl;   // print min_num and assign to answer2
    cout << "Largest number is " << (answer3 = max_num) << endl;    // print min_num and assign to answer3

    return 0;
}

