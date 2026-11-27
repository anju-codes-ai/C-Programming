
# Count Characters, Words, and Lines in a File in C

## Description
This program counts the total number of characters,
words, and newline characters in a text file using
C file handling functions.

## Objective
To understand how to read a file character by
character and calculate basic text statistics.

## Concepts Used
- File Handling
- FILE Pointer
- fopen()
- fgetc()
- fclose()
- EOF
- isspace()
- while Loop
- Conditional Statements

## How It Works
1. A FILE pointer is declared.
2. student.txt is opened in read mode ("r").
3. The program checks whether the file opened successfully.
4. fgetc() reads one character at a time.
5. The character counter increases for every character.
6. The line counter increases whenever a newline is found.
7. isspace() identifies whitespace between words.
8. The inWord variable tracks whether the program
   is currently inside a word.
9. The file is closed using fclose().
10. The total counts are displayed.

## Important Functions

| Function | Purpose |
|----------|---------|
| fopen() | Opens a file |
| fgetc() | Reads one character |
| isspace() | Checks whitespace characters |
| fclose() | Closes an opened file |

## Variables Used

| Variable | Purpose |
|----------|---------|
| characters | Counts all characters |
| words | Counts words |
| lines | Counts newline characters |
| inWord | Tracks whether a word is in progress |
| ch | Stores the character read from the file |

## File Mode
- "r" = Opens an existing file for reading.

## Sample Output

Total Characters: 73
Total Words: 12
Total Lines: 3

## Learning Outcome
After completing this program, you will understand
how to analyse text files and count characters,
words, and lines using C programming.

## Author
C Programming Practice
