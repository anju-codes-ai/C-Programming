# Number Guessing Game in C

## Project Overview

The Number Guessing Game is an interactive console-based application developed using the C programming language.

The application generates a random number, and the player attempts to guess it using hints provided by the program.

It also supports multiple difficulty levels and saves game results using file handling.

## Features

- Random number generation
- Three difficulty levels
- Too High and Too Low hints
- Automatic attempt counting
- Multiple game sessions
- Save player results
- View previous game results

## Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Editor:** Visual Studio Code
- **Storage:** Text File Handling

## Concepts Covered

- Functions
- Structures
- Loops
- Conditional statements
- Switch-case
- Random number generation
- Input validation
- File handling
- `rand()`, `srand()`, `time()`
- `fopen()`, `fprintf()`, `fgets()`, `fclose()`

## Project Structure

```text
04_Number_Guessing_Game/
│
├── main.c
└── README.md
```

The `game_results.txt` file is automatically created when a game result is saved.

## How to Compile and Run

### Compile

```bash
gcc main.c -o guessing
```

### Run on Windows

```bash
guessing.exe
```

### Run on Linux/macOS

```bash
./guessing
```

## How It Works

1. The player enters their name.
2. The player selects a difficulty level.
3. The application generates a random number.
4. The player enters guesses.
5. The application provides hints.
6. The number of attempts is calculated.
7. The result is saved in a text file.

## Learning Outcomes

Through this project, I practised:

- Implementing random number generation
- Developing logical thinking
- Using loops and conditional statements
- Creating reusable functions
- Working with structures
- Storing game results using file handling

## Future Improvements

- Add a maximum attempt limit
- Add a countdown timer
- Create a leaderboard
- Add multiplayer mode
- Add more difficulty levels

## Author

Created as a C programming practice project to strengthen programming fundamentals and logical problem-solving skills.

**Project Category:** Small C Programming Project

**Status:** Completed
