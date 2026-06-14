#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cctype>
using namespace std;

void MembersName()
{
    cout << "|Name                 |" << "|Roll No    |" << endl;
    cout << "|Tauqeer Bilal Hussain|" << "|F2024266319|" << endl;
    cout << "|Syed Kamil Taqi Zaidi|" << "|F2024266329|" << endl;
    cout << "|Tayyba Shahzad       |" << "|F2024266348|" << endl;
    cout << "|Omer Farooq          |" << "|F2024266330|" << endl;
    cout << "|Syed Mushtaq Hussain |" << "|F2024266318|" << endl << endl;

    cout << "Welcome to Hangman Game!" << endl << endl;
}

string getRandomWord(const string words[], int count)
{
    return words[rand() % count];
}

void displayCurrentWord(const string &displayWord)
{
    cout << "Current Word: " << displayWord << endl;
}

bool processLetterGuess(char guessedLetter, const string &correctWord, string &displayWord)
{
    bool found = false;
    for (int i = 0; i < correctWord.length(); i++)
    {
        if (correctWord[i] == guessedLetter && displayWord[i] == '_')
        {
            displayWord[i] = guessedLetter;
            found = true;
        }
    }
    return found;
}

void displayHangman(int wrongTries)
{
    cout << "  _______" << endl;
    cout << "  |     |" << endl;
    if (wrongTries >= 1)
        cout << "  O     |" << endl;
    if (wrongTries == 2)
        cout << " /|     |" << endl;
    if (wrongTries >= 3)
        cout << " /|\\    |" << endl;
    if (wrongTries >= 5)
        cout << "  |     |" << endl;
    if (wrongTries == 6)
        cout << " /      |" << endl;
    if (wrongTries >= 7)
        cout << " / \\    |" << endl;

    cout << "________|___" << endl;
}

void savedMan()
{
    cout << "  O     " << endl;
    cout << " /|\\    " << endl;
    cout << "  |     " << endl;
    cout << " / \\    " << endl;
    cout << "I am saved. Thank you! :)" << endl;
}

void playGame(int &player1Wins, int &player2Wins, int &roundsPlayed)
{
    string cities[] = {"lahore", "sialkot", "islamabad", "faisalabad", "rawalpindi", "multan", "quetta", "peshawar"};
    string animals[] = {"tiger", "elephant", "dolphin", "sparrow", "panda"};
    string countries[] = {"pakistan", "canada", "germany", "france", "italy"};

    
    int citiesCount = sizeof(cities) / sizeof(cities[0]);
    int animalsCount = sizeof(animals) / sizeof(animals[0]);
    int countriesCount = sizeof(countries) / sizeof(countries[0]);

    int mode;
    cout << "Select a mode to play: " << endl;
    cout << "1. Single Player." << endl;
    cout << "2. Multiplayer." << endl;

    while (true)
    {
        cin >> mode;
        if (cin.fail() || (mode != 1 && mode != 2))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Please select 1 or 2: ";
        }
        else
            break;
    }

    string correctWord;
    if (mode == 2)
    {
        cout << "Player 1, enter a word for Player 2 to guess: ";
        cin >> correctWord;
        for (int i = 0; i < correctWord.length(); i++)
            correctWord[i] = tolower(correctWord[i]); 
        system("cls"); 
    }
    else
    {
        cout << "Select a category: 1. Cities  2. Animals  3. Countries" << endl;
        int categoryChoice;

        while (true)
        {
            cin >> categoryChoice;
            if (cin.fail() || categoryChoice < 1 || categoryChoice > 3)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid choice! Please select 1, 2, or 3: ";
            }
            else
                break;
        }

        switch (categoryChoice)
        {
        case 1:
            correctWord = getRandomWord(cities, citiesCount);
            cout << "Category: Cities" << endl;
            break;
        case 2:
            correctWord = getRandomWord(animals, animalsCount);
            cout << "Category: Animals" << endl;
            break;
        case 3:
            correctWord = getRandomWord(countries, countriesCount);
            cout << "Category: Countries" << endl;
            break;
        }
    }

    string displayWord(correctWord.length(), '_');
    char userGuess;
    int wrongTries = 0, totalTries = 0;
    const int maxTries = 7;

    cout << "Guess the word letter by letter:" << endl;

    while (displayWord != correctWord && wrongTries < maxTries)
    {
    	cout << "Remaining tries: " << maxTries - wrongTries << endl;
        displayCurrentWord(displayWord);
        cout << "Enter a letter: ";
        cin >> userGuess;

        if (isalpha(userGuess) == false)
        {
            cout << "Special characters or digits are not allowed. Please enter a letter." << endl;
            continue;
        }

        userGuess = tolower(userGuess);
        totalTries++;

        if (processLetterGuess(userGuess, correctWord, displayWord) == false)
        {
            wrongTries++;
            cout << "Incorrect letter. Try again!" << endl;
            displayHangman(wrongTries);
        }
        else
        {
            cout << "Good guess!" << endl;
        }
    }

    if (displayWord == correctWord)
    {
        cout << "Congratulations! You saved the hangman by guessing the word: " << displayWord << endl;
        cout << "You solved it in " << totalTries << " tries." << endl;
        savedMan();
        if (mode == 2)
            player2Wins++;
        else
            player1Wins++;
    }
    else
    {
        cout << "Game Over! The hangman is complete. The correct word was: " << correctWord << endl;
        cout << "You made " << totalTries << " tries." << endl;
        displayHangman(wrongTries);
    }

    roundsPlayed++;
}

int main()
{
    srand(time(0));
    MembersName();

    int player1Wins = 0, player2Wins = 0, roundsPlayed = 0;
    char playAgain;

    do
    {
        playGame(player1Wins, player2Wins, roundsPlayed);

        cout << "\nScoreboard:" << endl;
        cout << "Player 1 Wins: " << player1Wins << endl;
        cout << "Player 2 Wins: " << player2Wins << endl;
        cout << "Rounds Played: " << roundsPlayed << endl;

        cout << "\nDo you want to play another round? (y/n): ";
        cin >> playAgain;

    } while (tolower(playAgain) == 'y');

    cout << "Thanks for playing! Final Scoreboard:" << endl;
    cout << "Player 1 Wins: " << player1Wins << endl;
    cout << "Player 2 Wins: " << player2Wins << endl;
    cout << "Rounds Played: " << roundsPlayed << endl;

    return 0;
}

