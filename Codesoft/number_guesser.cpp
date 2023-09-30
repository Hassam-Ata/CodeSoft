#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    cout << "\n\t\t\tWelcome to GuessTheNumber game!\n";
    cout << "You need to guess a number between 1 and 100. "
            "You'll have a limited number of attempts based on the "
            "level you choose. Good luck!\n";

    while (true) {
        cout << "\nEnter the difficulty level:\n";
        cout << "1 for easy\n";
        cout << "2 for medium\n";
        cout << "3 for difficult\n";
        cout << "0 to exit the game\n\n";

        int difficultyChoice;
        cout << "Enter your choice: ";
        cin >> difficultyChoice;

        if (difficultyChoice == 0) {
            cout << "Exiting the game. Goodbye!\n";
            break;
        }

        srand(time(0));
        int secretNumber = 1 + (rand() % 100);
        int playerChoice;
        int maxAttempts;

        if (difficultyChoice == 1)
            maxAttempts = 10;
        else if (difficultyChoice == 2)
            maxAttempts = 7;
        else if (difficultyChoice == 3)
            maxAttempts = 5;
        else {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        cout << "\nYou have " << maxAttempts << " attempts to find the secret number.\n";

        for (int attempt = 1; attempt <= maxAttempts; attempt++) {
            cout << "\nAttempt " << attempt << " - Enter your guess: ";
            cin >> playerChoice;

            if (playerChoice == secretNumber) {
                cout << "Congratulations! You guessed the correct number "
                        << playerChoice << ". You won!\n";
                break;
            } else if (playerChoice < secretNumber)
                cout << "Too low! Try a higher number.\n";
            else
                cout << "Too high! Try a lower number.\n";

            cout << "Attempts left: " << maxAttempts - attempt << "\n";

            if (attempt == maxAttempts)
                cout << "You couldn't find the secret number. It was " << secretNumber << ". You lose.\n";
        }

        cout << "\nDo you want to play again? (y/n): ";
        char playAgain;
        cin >> playAgain;

        if (playAgain == 'n' || playAgain == 'N') {
            cout << "Thank you for playing. Goodbye!\n";
            break;
        }
    }

    return 0;
}
