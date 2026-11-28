# Quiz Application in C

## Project Overview

The Quiz Application is a menu-driven console-based project developed using the C programming language.

It allows users to answer multiple-choice questions, calculate their scores, view their performance, and save quiz results using file handling.

## Features

- Multiple-choice quiz questions
- Four options for each question
- Automatic score calculation
- Correct and incorrect answer tracking
- Percentage calculation
- Performance feedback
- Save quiz results in a text file
- View previously saved results

## Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Editor:** Visual Studio Code
- **Storage:** Text File Handling

## Concepts Covered

- Structures (`struct`)
- Arrays
- Functions
- Loops
- Conditional statements
- Switch-case
- Strings
- File handling
- `fopen()`, `fprintf()`, `fgets()`, `fclose()`
- Input validation

## Project Structure

```text
03_Quiz_Application/
│
├── main.c
└── README.md
```

The `quiz_results.txt` file is automatically created when a quiz result is saved.

## How to Compile and Run

### Compile

```bash
gcc main.c -o quiz
```

### Run on Windows

```bash
quiz.exe
```

### Run on Linux/macOS

```bash
./quiz
```

## How It Works

1. The user opens the Quiz Application.
2. The user enters their name.
3. The application displays ten multiple-choice questions.
4. The user selects an answer for each question.
5. The application checks the answers and calculates the score.
6. The final result and percentage are displayed.
7. The result is saved in a text file.

## Learning Outcomes

Through this project, I practised:

- Designing a menu-driven application
- Using structures and arrays
- Creating reusable functions
- Applying conditional logic
- Processing user input
- Saving and retrieving data using file handling

## Future Improvements

- Add different quiz categories
- Add difficulty levels
- Randomize questions
- Add a timer
- Create a leaderboard
- Add an administrator question-management feature

## Author

Created as a C programming practice project to strengthen programming fundamentals and practical problem-solving skills.

**Project Category:** Small C Programming Project

**Status:** Completed
