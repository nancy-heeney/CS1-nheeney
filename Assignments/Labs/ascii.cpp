/*
    StdIO Lab
    ASCII Art - using literals and variables
    
    Updated By: Nancy Heeney
    Date: 14.02.2024
    
    This program produces an ASCII art on the console.

    Algorithm steps: 
    1. Use variables to store data/values
    2. Write a series of cout statements to print the data/values
*/

#include <iostream> //library for input and output
#include <string> //library for string data
 
using namespace std; //resolve cout, cin, and endl names
 
//main entry point of the program
int main()
{
    //FIXED: declare a variable to store name
    string name;
    //FIXED: prompt user to enter their name and store the value into name variable using getline function
    cout << "What is your name? " << endl;
    getline(cin, name);
    //FIXED: greet the name using the variable as the following output
    //must output: Nice meeting you, <name>!
    cout << "Nice meeting you," << name <<  "!" << endl;

    cout << "Hope you like my Tom & Jerry ASCII art...\n\n" << endl;

    string line1 = "  |\\_/|   **********************    (\\_/)\n";
    cout << line1;

    //FIXED: use variable to print the second line line of the graphic
    string line2 = " / @ @ \\  *    ASCII Lab       *   (='.'=)\n";
    cout << line2;
    //FIXED: print the third line of the graphics
    string line3 = "( > 0 < ) *     " +name+ "          * ( \" )_( \" )\n";
    cout << line3;
    //FIXED: use variable to print the fourth line
    string line4 = "  >>x<<   *    CSCI 110        *    \n";
    cout << line4;
    //FIXED: use variable to print the fifth line
    string line5 = " /  O  \\  ********************** ";
    cout << line5;
    //Note: You can add more lines or print more ASCII arts of your choice if you'd like...

    cout << "\nGood bye... hit enter to exit the program: " << '\n';
    //FIXED: make the console wait for user input
    cin.get();
    cin.get();
    return 0; //exit program by returning 0 status to the system
}