# Library Management System in C

## Project Overview

The Library Management System is a menu-driven console application developed using the C programming language.

It allows users to manage library book records, search for books, issue books, and return books. The application uses binary file handling to preserve book information between program sessions.

## Features

- Add new books
- Display all book records
- Search books using Book ID
- Issue available books
- Return issued books
- Track book availability
- Prevent duplicate Book IDs
- Save book records permanently

## Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Editor:** Visual Studio Code
- **Storage:** Binary File Handling

## Concepts Covered

- Structures (`struct`)
- Functions
- Loops
- Conditional statements
- Switch-case
- Strings
- File handling
- `fopen()`, `fread()`, `fwrite()`, `fclose()`
- `remove()` and `rename()`
- Input validation

## Project Structure

```text
05_Library_Management_System/
│
├── main.c
└── README.md
```

The `books.dat` file is generated automatically when book records are saved.

## How to Compile and Run

### Compile

```bash
gcc main.c -o library
```

### Run on Windows

```bash
library.exe
```

### Run on Linux/macOS

```bash
./library
```

## How It Works

1. The user opens the library application.
2. The user can add or view book records.
3. Books can be searched using their unique IDs.
4. Available books can be issued.
5. Issued books can be returned.
6. Book information is stored in a binary file.

## Learning Outcomes

Through this project, I practised:

- Managing structured data
- Developing menu-driven applications
- Implementing search operations
- Updating records using temporary files
- Understanding file handling
- Applying programming logic to a practical problem

## Future Improvements

- Add student or member registration
- Track who borrowed each book
- Add issue and return dates
- Calculate late return fees
- Add book categories
- Generate library reports

## Important Note

This is an educational console application. It does not include member authentication, borrowing history, or production-grade data recovery.

## Author

Created as a C programming practice project to strengthen programming fundamentals and practical problem-solving skills.

**Project Category:** Small C Programming Project

**Status:** Completed
