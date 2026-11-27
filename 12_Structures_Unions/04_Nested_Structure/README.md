
# 04 - Nested Structure in C

## 📌 Description
This program demonstrates the concept of **Nested Structures in C**.

A nested structure is a structure that contains another structure as one of its members. It helps organize related information into smaller and meaningful groups.

In this program, student information and address information are stored using two separate structures.

## 🎯 Objective
- Understand nested structures in C.
- Learn how to declare one structure inside another structure.
- Access members of an inner structure.
- Store and display organized student information.

## 🧠 Structure Declaration

```c
struct Address
{
    char city[50];
    int pinCode;
};

struct Student
{
    int rollNumber;
    char name[50];
    float marks;
    struct Address address;
};
```

## ⚙️ How It Works
1. The `Address` structure stores city and PIN code.
2. The `Student` structure stores roll number, name, marks, and an Address structure.
3. The program accepts student and address details.
4. The dot (`.`) operator accesses structure members.
5. The program displays all entered information.

## 💻 Sample Output

```text
Enter roll number: 101
Enter student name: Aarzoou
Enter marks: 92.5
Enter city: Mohali
Enter PIN code: 160059

----- Student Details -----
Roll Number: 101
Name: Aarzoou
Marks: 92.50
City: Mohali
PIN Code: 160059
```

## 📚 Concepts Used
- Structures
- Nested Structures
- Structure Members
- Dot (`.`) Operator
- `scanf()` and `printf()`

## ⏱️ Complexity Analysis
- **Time Complexity:** O(1) — A fixed number of fields are read and displayed.
- **Space Complexity:** O(1) — A fixed number of structure members are stored.

## 🚀 Learning Outcome
After completing this program, you will understand how to use one structure inside another to organize complex data.

## 📝 Important Note
To access a member of an inner structure, use the dot operator twice:

```c
s1.address.city
s1.address.pinCode
```

## 👩‍💻 Author
C Programming Practice Repository
