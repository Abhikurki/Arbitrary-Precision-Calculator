
# Arbitrary Precision Calculator (APC)

## 📌 Description
A C-based Arbitrary Precision Calculator using Doubly Linked List to perform arithmetic operations on large integers beyond standard data type limits. Supports addition, subtraction, multiplication, and division with efficient memory and modular design.

---

## 🚀 Features
- Handles very large numbers beyond `int` and `long` limits
- Supports:
  - Addition
  - Subtraction
  - Multiplication
  - Division
- Uses Doubly Linked List for efficient digit storage
- Modular code structure (separate files for each operation)
- Makefile for easy compilation

---

## 🧠 Data Structure Used
- Doubly Linked List (DLL)
- Each node stores a single digit
- Enables forward and backward traversal

---

## ⚙️ Compilation

```bash
make
```

---

## ▶️ Execution

```bash
./apc <number1> <operator> <number2>
```

### Example:
```bash
./apc 123 + 456
```

---

## 🧹 Clean Build Files

```bash
make clean
```

---

## 📂 Project Structure
- `APC_main.c` – Main driver file
- `DLL.c` – Linked list operations
- `Conversion.c` – String to DLL conversion
- `ADDITION.c` – Addition logic
- `SUBSTRACTION.c` – Subtraction logic
- `MULTIPLICATION.c` – Multiplication logic
- `DIVISION.c` – Division logic
- `APC.h` – Header file
- `Makefile` – Build automation

---

## 👨‍💻 Author
**Abhishek Y**

---

## 📚 Learning Outcomes
- Understanding of Data Structures
- Dynamic memory management in C
- Implementation of arithmetic logic at low level
- Modular programming and Makefile usage
