
# Append Data to an Existing File in C

## Description
This program demonstrates how to add new data at the
end of an existing text file without deleting its
previous content.

## Objective
To understand append mode and learn how to add data
to a file using C file handling functions.

## Concepts Used
- File Handling
- FILE Pointer
- fopen()
- fprintf()
- fclose()
- Append Mode ("a")

## How It Works
1. A FILE pointer is declared.
2. fopen() opens student.txt in append mode ("a").
3. The program checks whether the file opened successfully.
4. fprintf() adds new text at the end of the file.
5. fclose() closes the file.
6. A success message is displayed.

## Important Functions

| Function | Purpose |
|----------|---------|
| fopen() | Opens or creates a file |
| fprintf() | Writes formatted data |
| fclose() | Closes an opened file |

## File Mode

- "a" = Append mode.
- Creates the file if it does not exist.
- Adds new data at the end.
- Preserves existing content.

## Sample Output

Data appended successfully!

## Learning Outcome
After completing this program, you will understand
how to append new information to an existing file
without overwriting its previous data.

## Author
C Programming Practice
