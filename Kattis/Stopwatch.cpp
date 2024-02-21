/* algorith:
    collect input for number of following inputs of times
    if number is odd, input "Still running"
    if number is even:
        take difference between every other input and add to total time


*/
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main(void)
{
    int number;
    int total = 0;
    int num1, num2;
    string answer = "still running";

    cin >> number;

    if(number%2 == 0) //if even, loop through and find total seconds
    {
        for(int i=0; i<number / 2; i++)
        {
            cin >> num1 >> num2;
            total +=num2 - num1;
        }
    }
    else
    {
        cout << answer << endl;
    }
    
}