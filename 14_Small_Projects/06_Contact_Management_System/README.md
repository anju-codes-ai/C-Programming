# Contact Management System in C

## Project Overview

The Contact Management System is a menu-driven console application developed using the C programming language.

It allows users to store and manage contact information, including names, phone numbers, and email addresses. File handling is used to preserve contact records between program sessions.

## Features

- Add new contacts
- Display all saved contacts
- Search contacts by phone number
- Update existing contact details
- Delete contacts
- Prevent duplicate phone numbers
- Validate phone number input
- Store contact records permanently

## Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Editor:** Visual Studio Code
- **Storage:** Binary File Handling

## Concepts Covered

- Structures (`struct`)
- Functions
- Loops and conditional statements
- Switch-case
- Strings and string functions
- Character validation
- File handling
- `fopen()`, `fread()`, `fwrite()`, `fclose()`
- `strcmp()`, `strcspn()`
- `remove()` and `rename()`

## Project Structure

```text
06_Contact_Management_System/
│
├── main.c
└── README.md
```

The `contacts.dat` file is automatically created when contacts are saved.

## How to Compile and Run

### Compile

```bash
gcc main.c -o contacts
```

### Run on Windows

```bash
contacts.exe
```

### Run on Linux/macOS

```bash
./contacts
```

## How It Works

1. The user opens the contact management application.
2. The user can add a contact with a name, phone number, and email.
3. Contacts can be displayed or searched.
4. Existing contact information can be updated.
5. Unwanted contacts can be deleted.
6. Contact records are stored in a binary file.

## Learning Outcomes

Through this project, I practised:

- Managing structured records
- Using string-handling functions
- Validating user input
- Implementing CRUD operations
- Updating and deleting file records
- Building a practical menu-driven application

## Future Improvements

- Search contacts by name
- Sort contacts alphabetically
- Add contact categories
- Export contacts to a text file
- Add email format validation
- Create a graphical user interface

## Important Note

This is an educational console project. It stores contact information locally without encryption. Avoid using real private contact information in demonstration files.

## Author

Created as a C programming practice project to strengthen programming fundamentals and practical problem-solving skills.

**Project Category:** Small C Programming Project

**Status:** Completed
