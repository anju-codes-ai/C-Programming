
# Read and Display Data from a File in C

## Description
This program demonstrates how to open an existing
text file, read its contents character by character,
and display them on the screen.

## Objective
To understand how to read data from a file using
file handling functions in C.

## Concepts Used
- File Handling
- FILE Pointer
- fopen()
- fgetc()
- putchar()
- fclose()
- EOF (End Of File)

## How It Works
1. A FILE pointer is declared.
2. fopen() opens student.txt in read mode ("r").
3. The program checks whether the file opened successfully.
4. fgetc() reads one character at a time.
5. The loop continues until EOF is reached.
6. putchar() displays each character.
7. fclose() closes the file.

## Important Functions

| Function | Purpose |
|----------|---------|
| fopen() | Opens an existing file |
| fgetc() | Reads one character from a file |
| putchar() | Displays a character |
| fclose() | Closes an opened file |

## File Mode

- "r" = Read mode.
- Opens an existing file for reading.
- Fails if the file does not exist.

## Sample Output

File Contents:

Welcome to C Programming!
File handling is an important concept.
I am learning how to read files.

## Learning Outcome
After completing this program, you will understand
how to read and display file contents using C.

## Author
C Programming Practice
