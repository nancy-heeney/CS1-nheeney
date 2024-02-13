//cin >> fname >> lname >> age;
//sstream - main.cpp
// to get spaces put inbetween words or waht ever do cout << setw(15) << left << fname; - and so on






#include <iostream>
#include <sstream>
#include<cmath>
#include <iomanip>
using namespace std;

int main()
{
string fname, lname;
int age;

cout<< "Enter full name and age: " << endl;
//cin >> fname >> lname >> age;
getline(cin, phrase);

istringsstream iss (phrase); // Create an input string strean variable (which will act like a special cin), pass the phrase string in to process

cout << phrase << endl;

iss >> fname >> lname >> age;

cout << "Hello " << fname << ' ' << lname << ", says here you are " << age << " years old." << endl;



    return 0;
}