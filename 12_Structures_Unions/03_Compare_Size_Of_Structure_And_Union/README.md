
# 03 - Compare Size of Structure and Union in C

## 📌 Description
This program demonstrates the difference between the memory sizes of a structure and a union in C.

A structure allocates memory for all its members separately, while a union shares the same memory location among all its members.

The `sizeof()` operator is used to calculate and compare their sizes.

## 🎯 Objective
- Understand memory allocation in structures and unions.
- Learn the difference between `struct` and `union`.
- Use the `sizeof()` operator.
- Compare memory requirements of both data types.

## 🧠 Structure Declaration

```c
struct Data
{
    int number;
    float decimal;
    char character;
};
```

## 🧠 Union Declaration

```c
union DataUnion
{
    int number;
    float decimal;
    char character;
};
```

## ⚙️ How It Works
1. A structure named `Data` is declared.
2. A union named `DataUnion` is declared.
3. Variables of both types are created.
4. The `sizeof()` operator calculates their memory sizes.
5. Both sizes are displayed on the screen.

## 💻 Sample Output

```text
Size of Structure: 12 bytes
Size of Union: 4 bytes
```

## 📚 Concepts Used
- Structures
- Unions
- Memory Allocation
- `sizeof()` Operator
- Data Types
- Memory Alignment and Padding

## ⏱️ Complexity Analysis
- **Time Complexity:** O(1) — Both sizes are calculated using fixed-size types.
- **Space Complexity:** O(1) — One structure variable and one union variable are declared.

## 🚀 Learning Outcome
After completing this program, you will understand how structures and unions differ in memory allocation.

## 📝 Important Note

### Structure
- Each member has its own storage.
- Its size is generally based on the combined member sizes plus possible padding.

### Union
- All members share the same storage.
- Its size is generally based on the largest member, plus possible alignment padding.

Actual sizes depend on the compiler and platform.

## 👩‍💻 Author
C Programming Practice Repository
