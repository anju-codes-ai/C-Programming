# Student Management System in C

## Project Overview

The Student Management System is a menu-driven console application developed using the C programming language.

It allows users to manage student information and store records permanently using file handling.

## Features

- Add new student records
- Display all student records
- Search students using their ID
- Update existing student information
- Delete student records
- Prevent duplicate student IDs
- Store records in a binary file
- Load previously saved records when the program runs again

## Technologies Used

- **Language:** C
- **Compiler:** GCC
- **Editor:** Visual Studio Code
- **Storage:** Binary file handling

## Concepts Covered

- Structures (`struct`)
- Functions
- Arrays and strings
- Loops and conditional statements
- Switch-case
- File handling
- `fopen()`, `fread()`, `fwrite()`, `fclose()`
- `remove()` and `rename()`
- Input validation

## Project Structure

```text
01_Student_Management_System/
│
├── main.c
└── README.md
```

The `students.dat` file is generated automatically when student records are saved.

## How to Compile and Run

### Step 1: Compile

```bash
gcc main.c -o student
```

### Step 2: Run on Windows

```bash
student.exe
```

### Step 3: Run on Linux/macOS

```bash
./student
```

## Data Storage

Student records are stored in a binary file named `students.dat`.

The application uses file operations to:

- Append new student records
- Read existing records
- Rewrite records when updating information
- Create a temporary file when deleting or updating records

This allows student information to remain available after the application is closed.

## Learning Outcomes

Through this project, I practised:

- Building a menu-driven application
- Organizing code using functions
- Working with structures
- Performing CRUD operations
- Understanding persistent data storage
- Implementing file handling in C

## Future Improvements

- Add student marks and grades
- Calculate student results
- Sort records by student ID
- Add a graphical user interface
- Improve file recovery and error handling

## Author

Created as a C programming practice project to strengthen programming fundamentals and practical problem-solving skills.

---

**Project Category:** Small C Programming Project  
**Status:** Completed
