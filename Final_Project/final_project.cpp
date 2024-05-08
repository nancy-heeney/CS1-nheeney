#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const int NUM_WORDS = 20;
const int MAX_GUESSES = 6;

void drawHangman(int incorrectGuesses);

string words[NUM_WORDS] = {
    "apple", "banana", "cherry", "date", "elderberry",
    "fig", "grape", "honeydew", "ice cream", "jackfruit",
    "kiwi", "lemon", "mango", "nectarine", "orange",
    "pineapple", "quince", "raspberry", "strawberry", "tangerine"
};

string chooseRandomWord() {
    srand(time(0));
    return words[rand() % NUM_WORDS];       //function returns a random word from the words array
}                                           //This function ensures a different word is chosen each time it is called

void playHangman() {


    string word = chooseRandomWord();   //This line declares a string variable named word and assigns it a random word from a dictionary
    int wordLength = word.length();
    char guessedWord[wordLength + 1];
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '-';
    }
    guessedWord[wordLength] = '\0';

    int guessesRemaining = MAX_GUESSES;
    char guess;

    while (guessesRemaining > 0) {
        drawHangman(guessesRemaining);

        cout << "\nGive me a letter stupid: ";
        cin >> guess;

        bool correctGuess = false;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            guessesRemaining--;
            cout << "\nThat's a stupid guess. You have " << guessesRemaining << " guesses remaining.\n";
        }

        cout << "\nHere's the word you're trying to guess: " << guessedWord << "\n";

        bool wordGuessed = true;
        for (int i = 0; i < wordLength; i++) {
            if (guessedWord[i] == '-') {
                wordGuessed = false;
                break;
            }
        }

        if (wordGuessed) {
            cout << "\nCongratulations, you're not stupid! You did it: " << word << "\n";
            return;
        }
    }

    cout << "\nYou're stupid! You died! The word was: " << word << "\n";
}

int main() {
    playHangman();
    return 0;
}