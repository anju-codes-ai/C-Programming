
# 05 - Passing Structure to Function in C

## 📌 Description
This program demonstrates how to pass a structure variable as an argument to a function in C.

A structure can be passed to a function just like other variables. This allows a function to receive and process multiple related data members together.

In this program, student details are accepted in the `main()` function and passed to a separate function for displaying.

## 🎯 Objective
- Understand how to pass structures to functions.
- Learn how structure variables work as function arguments.
- Separate input and display operations.
- Improve code organization and reusability.

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
2. The program accepts student details.
3. The structure variable `s1` is passed to `displayStudent()`.
4. The function receives the structure through its parameter.
5. The function displays all student details.

## 💻 Sample Output

```text
Enter roll number: 101
Enter student name: Aarzoou
Enter marks: 92.5

----- Student Details -----
Roll Number: 101
Name: Aarzoou
Marks: 92.50
```

## 📚 Concepts Used
- Structures
- User-Defined Functions
- Structure as Function Argument
- Function Parameters
- Dot (`.`) Operator

## ⏱️ Complexity Analysis
- **Time Complexity:** O(1) — A fixed number of fields are processed.
- **Space Complexity:** O(1) — A fixed-size structure is used.

## 🚀 Learning Outcome
After completing this program, you will understand how to pass structure variables to functions and organize programs using separate functions.

## 📝 Important Note
The function receives a copy of the structure because it is passed by value.

```c
displayStudent(s1);
```

Changes made to the function's local structure parameter do not change the original structure variable.

## 👩‍💻 Author
C Programming Practice Repository
