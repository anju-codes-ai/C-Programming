# Banking Management System in C

## Project Overview

The Banking Management System is a menu-driven console application developed using the C programming language.

It allows users to create and manage bank accounts, perform basic deposit and withdrawal operations, and store account information permanently using file handling.

## Features

- Create a new bank account
- Display all bank accounts
- Search accounts using account numbers
- Deposit money
- Withdraw money
- Check available account balance
- Prevent duplicate account numbers
- Store account records in a binary file
- Preserve account information after program termination
- Validate basic user input

## Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Editor:** Visual Studio Code
- **Storage:** Binary File Handling

## Concepts Covered

- Structures (`struct`)
- User-defined functions
- Loops and conditional statements
- Switch-case
- Strings
- File handling
- `fopen()`, `fread()`, `fwrite()`, `fclose()`
- `remove()` and `rename()`
- Input validation

## Project Structure

```text
02_Banking_Management_System/
│
├── main.c
└── README.md
```

The `accounts.dat` file is automatically generated when account records are saved.

## How to Compile and Run

### Compile

```bash
gcc main.c -o banking
```

### Run on Windows

```bash
banking.exe
```

### Run on Linux/macOS

```bash
./banking
```

## File Handling

The application stores account details in `accounts.dat`.

It uses binary file operations to:
- Save new accounts
- Read account records
- Update account balances
- Preserve account information between program sessions

## Learning Outcomes

Through this project, I practised:

- Building a menu-driven C application
- Managing structured records
- Performing basic banking operations
- Working with persistent file storage
- Handling transactions and validating input
- Organizing a project using functions

## Future Improvements

- Add transaction history
- Add account authentication
- Generate account statements
- Add account deletion
- Improve error recovery
- Use a database for more advanced storage

## Important Note

This is an educational console project, not real banking software. It does not implement secure authentication, encryption, audit logs, or production-grade transaction recovery.

## Author

Created as a C programming practice project to improve programming fundamentals and practical problem-solving skills.

**Project Category:** Small C Programming Project

**Status:** Completed
