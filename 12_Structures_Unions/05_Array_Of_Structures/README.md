
# 05 - Array of Structures in C

## 📌 Description
This program demonstrates the concept of **Array of Structures in C**.

An array of structures is used to store multiple records of the same structure type. Each array element represents one complete record containing multiple data members.

In this program, student roll numbers, names, and marks are stored and displayed using an array of structures.

## 🎯 Objective
- Understand arrays of structures.
- Store multiple student records.
- Access structure members using array indexing.
- Use loops to input and display records.

## 🧠 Structure Declaration

```c
struct Student
{
    int rollNumber;
    char name[50];
    float marks;
};
```

## ⚙️ How It Works
1. A structure named `Student` is declared.
2. An array of three Student records is created.
3. A `for` loop accepts details of each student.
4. Each record is accessed using its array index.
5. Another `for` loop displays all student records.

## 💻 Sample Output

```text
===== All Student Records =====

Student 1
Roll Number: 101
Name: Aarzoou
Marks: 92.50

Student 2
Roll Number: 102
Name: Rahul
Marks: 85.00

Student 3
Roll Number: 103
Name: Priya
Marks: 90.00
```

## 📚 Concepts Used
- Structures
- Array of Structures
- `for` Loop
- Array Indexing
- Structure Members
- `scanf()` and `printf()`

## ⏱️ Complexity Analysis
Let n represent the number of students.

- **Time Complexity:** O(n) — Each student record is processed once for input and once for display.
- **Space Complexity:** O(n) — Memory is used to store n student records.

## 🚀 Learning Outcome
After completing this program, you will understand how to manage multiple records using an array of structures.

## 📝 Important Note
An array of structures is declared as:

```c
struct Student students[SIZE];
```

A member is accessed using the array index and dot operator:

```c
students[i].rollNumber
students[i].name
students[i].marks
```

Array indexing starts from 0.

## 👩‍💻 Author
C Programming Practice Repository
