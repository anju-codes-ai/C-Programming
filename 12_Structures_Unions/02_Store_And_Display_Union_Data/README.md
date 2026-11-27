
# 02 - Store and Display Union Data in C

## 📌 Description
This program demonstrates how to store and display data using a union in C.

A union allows different data members to share the same memory location. This program accepts employee ID, salary, and grade one at a time and displays each value immediately after assigning it.

## 🎯 Objective
- Learn how to store values in union members.
- Understand how to access union members.
- Practice taking user input using `scanf()`.
- Understand memory sharing in unions.

## 🧠 Union Declaration

```c
union Employee
{
    int employeeID;
    float salary;
    char grade;
};
```

## ⚙️ How It Works
1. A union named `Employee` is declared.
2. A union variable named `emp` is created.
3. The program accepts an employee ID and displays it.
4. It accepts a salary and displays it.
5. Finally, it accepts and displays the employee grade.
6. Each member is displayed immediately after assignment.

## 💻 Sample Output

```text
Enter employee ID: 101

Employee ID: 101

Enter employee salary: 35000
Employee Salary: 35000.00

Enter employee grade: A
Employee Grade: A
```

## 📚 Concepts Used
- Union Declaration
- Union Members
- Shared Memory
- `scanf()` and `printf()`
- Dot (`.`) Operator

## ⏱️ Complexity Analysis
- **Time Complexity:** O(1) — A fixed number of input and output operations are performed.
- **Space Complexity:** O(1) — Only one union variable is used.

## 🚀 Learning Outcome
After completing this program, you will understand how to accept, store, and display values using union members.

## 📝 Important Note
All members of a union share the same memory location.

When a new member is assigned a value, it replaces the previously stored value. Therefore, access the member whose value was most recently assigned.

## 👩‍💻 Author
C Programming Practice Repository
