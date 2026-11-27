
# 01. Student Details Using Structure

## 📌 Description
This C program demonstrates the use of structures to store and display student information.

A structure is a user-defined data type that allows multiple variables of different data types to be grouped under one name.

The program stores a student's roll number, name, and marks using a structure.

## 🎯 Objective
- Understand structures in C.
- Learn how to declare a structure.
- Store different data types in one structure.
- Access structure members using the dot (.) operator.

## 💻 Example
Student Details:

Roll Number: 101  
Name: Aarzoou  
Marks: 92.50

## ⚙️ How It Works
1. A structure named `Student` is declared.
2. Three members are created: roll number, name, and marks.
3. A structure variable `s1` is declared.
4. The program accepts student information from the user.
5. The dot (.) operator accesses individual structure members.
6. The student's details are displayed.

## 🔑 Structure Syntax
```c
struct Student
{
    int rollNumber;
    char name[50];
    float marks;
};
```

## 📤 Sample Output
```text
Enter student roll number: 101
Enter student name: Aarzoou
Enter student marks: 92.5

----- Student Details -----
Roll Number: 101
Name: Aarzoou
Marks: 92.50
```

## 🧠 Concepts Used
- Structures
- User-defined data types
- Structure declaration
- Structure variables
- Dot (.) operator
- scanf() and printf()

## ⏱️ Time Complexity
O(1)

## 💾 Space Complexity
O(1), as the program stores a fixed number of student fields.

## 📚 Learning Outcome
After completing this program, you will understand how structures group different types of data and how to access structure members.

## ⚠️ Important Notes
- A structure is declared using the `struct` keyword.
- Each structure member has its own data type.
- The dot (.) operator is used to access structure members.
- Structure members have separate storage within the structure, subject to compiler padding and alignment.

---
**Category:** Structures  
**Language:** C
```

### 4. GitHub Folder Structure

```text
09_Structures/
│
└── 01_Student_Details_Using_Structure/
    ├── main.c
    └── README.md
```

<badge color="success">Program 01 Completed</badge>

**Next → Program 02: Store and Display Employee Details Using Structure.**
