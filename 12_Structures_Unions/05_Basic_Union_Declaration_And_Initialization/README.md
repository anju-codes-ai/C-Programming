
# 05 - Basic Union Declaration and Initialization in C

## 📌 Description
This program demonstrates the basic declaration and initialization of a union in C.

A union is a user-defined data type in which all members share the same memory location. Unlike a structure, a union generally stores a meaningful value in one member at a time.

This program demonstrates how to declare a union and assign values to its different members.

## 🎯 Objective
- Understand the concept of unions in C.
- Learn how to declare a union.
- Access union members using the dot operator.
- Understand shared memory in unions.

## 🧠 Union Declaration

```c
union Data
{
    int number;
    float decimal;
    char character;
};
```

## ⚙️ How It Works
1. A union named `Data` is declared.
2. It contains three members: integer, float, and character.
3. A union variable `d` is created.
4. A value is assigned to the integer member and displayed.
5. A float value is assigned and displayed.
6. Finally, a character value is assigned and displayed.

## 💻 Sample Output

```text
Union Member Values
Integer Number: 100

After assigning float value:
Decimal Number: 25.50

After assigning character value:
Character: A
```

## 📚 Concepts Used
- Union Declaration
- Union Variables
- Memory Sharing
- Union Members
- Dot (`.`) Operator
- `printf()` Function

## ⏱️ Complexity Analysis
- **Time Complexity:** O(1) — A fixed number of assignments and display operations are performed.
- **Space Complexity:** O(1) — Only one union variable is created.

## 🚀 Learning Outcome
After completing this program, you will understand how unions are declared, how their members are accessed, and how memory is shared among members.

## 📝 Important Note
All union members share the same memory location.

The size of a union is generally based on its largest member, with possible additional padding for alignment.

Only the member most recently assigned should be read as the active stored value.

## 👩‍💻 Author
C Programming Practice Repository
