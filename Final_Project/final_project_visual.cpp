#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

void drawHangman(int incorrectGuesses) {
    if (incorrectGuesses == 6) {
        cout << "  ________\n";
        cout << " |/\n";
        cout << " |\n";
        cout << " |\n";
        cout << " |\n";
        cout << " |\n";
        cout << "_\n";
    } else if (incorrectGuesses == 5) {
        cout << "  ________\n";
        cout << " |/   |\n";
        cout << " |    |\n";
        cout << " |    O\n";
        cout << " |\n";
        cout << " |\n";
        cout << "_\n";
    } else if (incorrectGuesses == 4) {
        cout << "  ________\n";
        cout << " |/   |\n";
        cout << " |    |\n";
        cout << " |    O\n";
        cout << " |   /|\n";
        cout << " |\n";
        cout << "_\n";
    } else if (incorrectGuesses == 3) {
        cout << "  ________\n";
        cout << " |/   |\n";
        cout << " |    |\n";
        cout << " |    O\n";
        cout << " |   /|\\\n";
        cout << " |\n";
        cout << "_\n";
    } else if (incorrectGuesses == 2) {
        cout << "  ________\n";
        cout << " |/   |\n";
        cout << " |    |\n";
        cout << " |    O\n";
        cout << " |   /|\\\n";
        cout << " |   /\n";
        cout << "_\n";
    } else if (incorrectGuesses == 1) {
        cout << "  ________\n";
        cout << " |/   |\n";
        cout << " |    |\n";
        cout << " |    O\n";
        cout << " |   /|\\\n";
        cout << " |   / \\\n";
        cout << "_\n";
    }
}
