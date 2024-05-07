/*
    Loops Lab
    Updated By: Nancy Heeney
    CSCI 111
    Date: 03.15.2024

    Program prints geometric shapes of given height with * using loops
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void printTriangle(int height) {
    //Function takes height as an argument to print the triangle
    //of that height with *
    int row = 1;
    // row
    while (row <= height) {
        // column
        for(int col = 1; col<=row; col++)
            cout << "* ";
        row += 1;
        cout << endl;
    }
}


void printFlippedTriangle(int height) 
{
    for (int i = height; i >= 1; --i) 
    {
        for (int j = 1; j <= i; ++j) 
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}
    /* 
    Implement the function that takes height as an argument
    and prints a triangle with * of given height.
    Triangle of height 5, e.g., should look like the following.
    * * * * *
    * * * *
    * * *
    * *
    *
    
    */
    // FIXED ...



/*  
FIXED
Design and implement a function that takes an integer as height and
prints square of the given height with *.
Square of height 5, e.g., would look like the following.

*  *  *  *  *  
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   

*/
void printSquare(int height) 
{
    for (int i = 1; i <= height; ++i) 
    {
        for (int j = 1; j <= height; ++j) 
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

// function clears the screen system call
// NOTE: system call is not a security best pracice!
void clearScreen() 
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

int main(int argc, char* argv[]) 
{
    cout << "Hello!!!\n";
    // FIXED add a loop to make the program to continue to run until the user wants to quit
    int height;
    char choice;
    do 
    {
        std::cout << "Enter the height of the square: ";
        std::cin >> height;
        printSquare(height);
        std::cout << "Do you want to continue? (y/n): ";
        std::cin >> choice;
     
    } 
    while (choice == 'y' || choice == 'Y');

    // FIXED call clearScreen function to clear the screen for each round of the loop
    cout << "Program prints geometric shapes of given height with *\n";
    cout << "Please enter the height of the shape: ";
    cin >> height;
    // call printTriangle function passing user entered height
    printTriangle(height);

    // FIXED
    // Call printFlippedTriangle passing proper argument
    printFlippedTriangle(height);
    // Manually test the function

    // FIXED
    // Call the function defined in FIXME4 passing proper argument
    printSquare(height);
    // Manually test the function

    // FIXME9
    // prompt user to enter y/Y to continue anything else to quit

    // FIXME10
    // Use conditional statements to break the loop or continue the loop

    // Check if the user wants to continue
    if (choice != 'y' && choice != 'Y') 
    {
        std::cout << "Exiting the program..." << std::endl;
        // Use 'continue' to skip the rest of the loop and start a new iteration
        // continue;
    }

        // Clear the screen
        system("cls");


    return 0;
}