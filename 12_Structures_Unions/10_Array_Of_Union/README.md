
# 10 - Array of Union in C

## 📌 Description
This program demonstrates the concept of an Array of Unions in C.

An array of unions is used to create multiple union variables of the same type. Each array element represents a separate union object.

In this program, an array of three union elements is used to store and display integer values.

## 🎯 Objective
- Understand arrays of unions.
- Learn how to declare an array of union variables.
- Access union members using array indexing.
- Use loops to input and display values.

## 🧠 Union Declaration

```c id="u9jdq5"
union Data
{
    int number;
    float decimal;
};
```

## ⚙️ How It Works
1. A union named `Data` is declared.
2. An array of three union variables is created.
3. A `for` loop accepts integer values.
4. Each element is accessed using its array index.
5. Another `for` loop displays all stored values.

## 💻 Sample Output

```text id="w87xql"
Enter number 1: 10
Enter number 2: 20
Enter number 3: 30

----- Array of Union Values -----
Number 1: 10
Number 2: 20
Number 3: 30
```

## 📚 Concepts Used
- Unions
- Array of Unions
- Array Indexing
- `for` Loop
- Union Members
- `scanf()` and `printf()`

## ⏱️ Complexity Analysis
Let n represent the number of array elements.

- **Time Complexity:** O(n) — Each element is processed once for input and once for display.
- **Space Complexity:** O(n) — Memory is allocated for n union elements.

## 🚀 Learning Outcome
After completing this program, you will understand how to create and manage multiple union variables using an array.

## 📝 Important Note
An array of unions is declared as:

```c id="ed24s7"
union Data values[SIZE];
```

A union member is accessed using the array index and dot operator:

```c id="y4v8su"
values[i].number
```

Each array element has separate storage, but the members within each individual union share memory.

## 👩‍💻 Author
C Programming Practice Repository
