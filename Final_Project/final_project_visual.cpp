#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

void drawHangman(int incorrectGuesses) {
    if (incorrectGuesses == 1) {
        cout << "  ________\n";
        cout << " |/\n";
        cout << " |\n";
        cout << " |\n";
        cout << " |\n";
        cout << " |\n";
        cout << "_\n";
    } else if (incorrectGuesses == 2) {
        cout << "  ________\n";
        cout << " |/   |\n";
        cout << " |    |\n";
        cout << " |    O\n";
        cout << " |\n";
        cout << " |\n";
        cout << "_\n";
    } else if (incorrectGuesses == 3) {
        cout << "  ________\n";
        cout << " |/   |\n";
        cout << " |    |\n";
        cout << " |    O\n";
        cout << " |   /|\n";
        cout << " |\n";
        cout << "_\n";
    } else if (incorrectGuesses == 4) {
        cout << "  ________\n";
        cout << " |/   |\n";
        cout << " |    |\n";
        cout << " |    O\n";
        cout << " |   /|\\\n";
        cout << " |\n";
        cout << "_\n";
    } else if (incorrectGuesses == 5) {
        cout << "  ________\n";
        cout << " |/   |\n";
        cout << " |    |\n";
        cout << " |    O\n";
        cout << " |   /|\\\n";
        cout << " |   /\n";
        cout << "_\n";
    } else if (incorrectGuesses == 6) {
        cout << "  ________\n";
        cout << " |/   |\n";
        cout << " |    |\n";
        cout << " |    O\n";
        cout << " |   /|\\\n";
        cout << " |   / \\\n";
        cout << "_\n";
    }
}

int main() {
    srand(time(0));
    string wordBank[20] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "ice cream", "jackfruit", "kiwi", "lemon", "mango", "nectarine", "orange", "pineapple", "quince", "raspberry", "strawberry", "tangerine"};
    string word = wordBank[rand() % 20];
    int wordLength = word.length();
    int incorrectGuesses = 0;
    string correctGuesses;
    for (int i = 0; i < wordLength; i++) {
        correctGuesses += "-";
    }

    while (incorrectGuesses < 6 && correctGuesses != word) {
        cout << "Current word: " << correctGuesses << endl;
        cout << "Incorrect guesses: ";
        for (int i = 0; i < wordLength; i++) {
            if (word[i] != correctGuesses[i]) {
                cout << word[i] << " ";
            }
        }
        cout << endl;
        drawHangman(incorrectGuesses);

        char guess;
        cout << "Enter a letter: ";
        cin >> guess;

        if (word.find(guess) != string::npos) {
            for (int i = 0; i < wordLength; i++) {
                if (word[i] == guess) {
                    correctGuesses[i] = guess;
                }
            }
        } else {
            incorrectGuesses++;