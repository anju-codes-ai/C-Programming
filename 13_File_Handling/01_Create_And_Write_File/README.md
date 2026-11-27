
# Create a File and Write Data into It in C

## Description
This program demonstrates how to create a file and
write text data into it using file handling functions
in the C programming language.

## Objective
To understand how to create a file, write data into
it, and close the file safely.

## Concepts Used
- File Handling
- FILE Pointer
- fopen()
- fprintf()
- fclose()
- File Opening Modes

## How It Works
1. A FILE pointer is declared.
2. fopen() opens student.txt in write mode ("w").
3. The program checks whether the file opened successfully.
4. fprintf() writes text into the file.
5. fclose() closes the file.
6. A success message is displayed.

## Important Functions

| Function | Purpose |
|----------|---------|
| fopen() | Opens or creates a file |
| fprintf() | Writes formatted data into a file |
| fclose() | Closes an opened file |

## File Mode

- "w" = Write mode.
- Creates a new file if it does not exist.
- Overwrites existing content if the file already exists.

## Sample Output

Data written successfully into the file.

## File Content

Welcome to C File Handling!
This is my first file handling program.

## Learning Outcome
After completing this program, you will understand
how to create a file and store text data using C.

## Author
C Programming Practice
