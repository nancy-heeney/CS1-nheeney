/*
Library Functions Lab
Updated By: Nancy Heeney 
CSCI 111
Date: I don't know

Program prompts user to enter a decimal number. It then finds various trig and mathematical values 
of the number using library functions and prints the results using cstdio's printf function.

Algorithm:
    1. Prompt user to enter a decmial number
    2. Store the number into a variable
    3. Find and print various results form the number
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <cmath> // various math functions: https://cplusplus.com/reference/cmath
using namespace std;

int main()
{
    double number, result;

    cout << "Program calculates various results from a given number" << endl;
    cout << "Enter a decimal number: ";
    cin >> number;
    // Find ceiling of the number
    result = ceil(number);
    printf("ceiling(%f) = %.1f\n", number, result);
    // Find floor of the number
    result = floor(number);
    printf("Floor(%f) = %.1f\n", number, result);
    //FIXED - Using library function, find and print the square root of the number upto 2 decimal points
    cout << "The square root of your number is: " << fixed << setprecision(2) << sqrt(number) << endl;
    //FIXED - Using library function, find and print the cube root of the number upto 2 decimal points
    cout << "The cube root of your number is: " << fixed << setprecision(2) << cbrt(number) << endl;
    //FIXED - Using library function, find and print the 10th power of the number upto 2 decimal points
    cout << "The 10th power of your number is: " << fixed << setprecision(2) << pow(number,10) << endl;
    //FIXED - Using library function, find and print the log_2 of the number upto 2 decimal points
    cout << "The log_2 of your number is: " << fixed << setprecision(2) << log2(number) << endl;
    //FIXED - Using library function, find and print the log_10 of the number upto 2 decimal points
    cout << "The log_10 of your number is: " << fixed << setprecision(2) << log10(number) << endl;
    //FIXED - Convert number into radians and store into a variable
    double rad = number * (M_PI/180);
    //FIXED - Using library function, find and print the sine of the radian value in FIXME 8 upto 2 decimal points
    cout << "The sin of your number is: " << fixed << setprecision(2) << sin(number) << endl;
    //FIXED - Using library function, find and print the cosine of the radian value in FIXME 8 upto 2 decimal points
    cout << "The cos of your number is: " << fixed << setprecision(2) << cos(number) << endl;

    cin.ignore(1000, '\n');
    cout << "Enter to quit the program: ";
    cin.get();
    cout << "Good bye..." << endl;
    return 0;
}