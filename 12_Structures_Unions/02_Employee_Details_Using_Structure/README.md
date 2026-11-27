
# 02. Employee Details Using Structure

## 📌 Description
This C program demonstrates how to store and display employee information using a structure.

It groups employee ID, name, and salary into a single user-defined data type.

## 🎯 Objective
- Understand structure declaration.
- Store different data types together.
- Access structure members.
- Learn practical applications of structures.

## 💻 Example
Employee Details:

Employee ID: 101  
Employee Name: Rahul Sharma  
Salary: 35000.00

## ⚙️ How It Works
1. A structure named `Employee` is declared.
2. Three members are created: employee ID, name, and salary.
3. A structure variable `emp` is declared.
4. The program accepts employee information.
5. The dot (.) operator accesses each member.
6. The employee details are displayed.

## 🔑 Structure Syntax
```c
struct Employee
{
    int employeeID;
    char name[50];
    float salary;
};
```

## 📤 Sample Output
```text
Enter employee ID: 101
Enter employee name: Rahul Sharma
Enter employee salary: 35000

----- Employee Details -----
Employee ID: 101
Employee Name: Rahul Sharma
Salary: 35000.00
```

## 🧠 Concepts Used
- Structures
- User-defined data types
- Structure variables
- Character arrays
- Dot (.) operator
- scanf() and printf()

## ⏱️ Time Complexity
O(1)

## 💾 Space Complexity
O(1), as a fixed number of employee fields are stored.

## 📚 Learning Outcome
After completing this program, you will understand how structures can organize related employee information into a single unit.

## ⚠️ Important Notes
- The `struct` keyword is used to declare a structure.
- Different data types can be grouped together.
- The dot (.) operator accesses structure members.
- `fgets()` or a width-limited scanf format can be used to read names containing spaces.

---
**Category:** Structures  
**Language:** C
```

### 4. GitHub Folder Structure

```text
09_Structures/
│
└── 02_Employee_Details_Using_Structure/
    ├── main.c
    └── README.md
```

<badge color="success">Program 02 Completed</badge>

**Next → Program 03: Array of Structures** — an especially important topic for practicals and exams.
