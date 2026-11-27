
# 04 - Access Union Members in C

## 📌 Description
This program demonstrates how to access and update different members of a union in C.

A union allows all its members to share the same memory location. Members can be accessed using the dot (`.`) operator.

This program assigns values to the roll number, marks, and grade members one at a time and displays each value.

## 🎯 Objective
- Learn how to access union members.
- Understand the dot (`.`) operator.
- Practice assigning values to union members.
- Understand shared memory in unions.

## 🧠 Union Declaration

```c
union Student
{
    int rollNumber;
    float marks;
    char grade;
};
```

## ⚙️ How It Works
1. A union named `Student` is declared.
2. A union variable named `s` is created.
3. A value is assigned to `rollNumber` and displayed.
4. A value is assigned to `marks` and displayed.
5. A character is assigned to `grade` and displayed.
6. Each member is accessed immediately after assignment.

## 💻 Sample Output

```text
Roll Number: 101

Marks: 92.50

Grade: A
```

## 📚 Concepts Used
- Union Declaration
- Union Members
- Member Access
- Dot (`.`) Operator
- Shared Memory

## ⏱️ Complexity Analysis
- **Time Complexity:** O(1) — A fixed number of assignments and display operations are performed.
- **Space Complexity:** O(1) — Only one union variable is created.

## 🚀 Learning Outcome
After completing this program, you will understand how to access and update union members correctly.

## 📝 Important Note
All union members share the same memory location.

When a new member is assigned a value, the previously stored value is overwritten. Always read the member whose value was most recently assigned.

## 👩‍💻 Author
C Programming Practice Repository
