
# Copy Contents of One File to Another in C

## Description
This program demonstrates how to copy the complete
contents of one text file into another using file
handling functions in C.

## Objective
To understand how to read data from a source file
and write the same data into a destination file.

## Concepts Used
- File Handling
- FILE Pointer
- fopen()
- fgetc()
- fputc()
- fclose()
- EOF (End Of File)

## How It Works
1. Two FILE pointers are declared.
2. source.txt is opened in read mode ("r").
3. destination.txt is opened in write mode ("w").
4. The program checks whether both files opened successfully.
5. fgetc() reads one character from the source file.
6. fputc() writes that character into the destination file.
7. The process continues until EOF is reached.
8. Both files are closed using fclose().

## Important Functions

| Function | Purpose |
|----------|---------|
| fopen() | Opens a file |
| fgetc() | Reads one character |
| fputc() | Writes one character |
| fclose() | Closes a file |

## File Modes

- "r" = Opens source file for reading.
- "w" = Creates or overwrites destination file.

## Sample Output

File copied successfully!

## Learning Outcome
After completing this program, you will understand
how to transfer data from one file to another using
character-by-character file operations.

## Author
C Programming Practice
