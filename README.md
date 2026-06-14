# 🪓 Hangman Game

A fully-featured console-based Hangman game written in C++. Supports both single-player (with word categories) and two-player modes, complete with an ASCII hangman display and a live scoreboard.

## 🎮 Features

- **Single Player mode** — guess randomly selected words from 3 categories
- **Multiplayer mode** — Player 1 sets a word, Player 2 guesses
- **3 word categories** — Cities, Animals, Countries
- **ASCII Hangman** — visual gallows that builds with each wrong guess
- **7 chances** before the hangman is complete
- **Scoreboard** — tracks wins and rounds played across multiple games
- **Input validation** — blocks digits, special characters, and invalid choices

## 🚀 How to Run

**Requirements:** Any C++ compiler (g++, Dev-C++, VS Code with MinGW)

```bash
# Compile
g++ Hangman.cpp -o hangman

# Run
./hangman
```

Or open in **Dev-C++** and hit Run.

## 📸 Sample Output

```
Current Word: _ _ _ _ _ _
Enter a letter: a
Incorrect letter. Try again!
  _______
  |     |
  O     |
 /|\    |
________|___

Remaining tries: 4
```

## 🗂️ Word Bank

| Category | Words |
|---|---|
| Cities | Lahore, Sialkot, Islamabad, Faisalabad, Rawalpindi, Multan, Quetta, Peshawar |
| Animals | Tiger, Elephant, Dolphin, Sparrow, Panda |
| Countries | Pakistan, Canada, Germany, France, Italy |

## 👥 Team

| Name | Roll No |
|---|---|
| Syed Kamil Taqi Zaidi | F2024266329 |
| Tauqeer Bilal Hussain | F2024266319 |
| Tayyba Shahzad | F2024266348 |
| Omer Farooq | F2024266330 |
| Syed Mushtaq Hussain | F2024266318 |

## 🏫 Course

**Programming Fundamentals** — University of Management and Technology (UMT), Lahore
