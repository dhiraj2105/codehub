## 📘 Calculator Console Application (C++)

A modular, self-contained console calculator built in C++ — featuring manual arithmetic logic (no built-in math functions), clear terminal UI, and robust history tracking with undo/redo functionality.

---

### 📁 Project Structure

```
project-root/
├── include/             # All header files
│   ├── Calculator.h
│   ├── Operation.h
│   ├── OperationStack.h
│   ├── History.h
│   └── ColorUtils.h
├── src/                 # All source files
│   ├── main.cpp
│   ├── Calculator.cpp
│   ├── Operation.cpp
│   ├── OperationStack.cpp
│   ├── History.cpp
├── Makefile             # Build instructions
```

---

## 🔧 Features

### ✅ Manual Arithmetic Logic

- Fully implemented math operations (addition, subtraction, multiplication, division, modulo, power)
- **No built-in math functions** are used — everything is implemented from scratch

### ✅ Clean Modular Structure

- Each functionality is encapsulated in a well-named `.cpp` and `.h` file
- Utility functions (e.g., color output) are isolated in a reusable header

### ✅ Easy-to-Use Menu Interface

- Choose from options like calculate, view history, undo, redo, and exit
- Clear, colored output improves readability and user experience

### ✅ Recent History Feature (🔥 Highlight)

- Automatically keeps track of the **last 5 operations**
- Oldest entries are discarded as new ones are added
- View recent operations anytime from the menu

---

## 🚀 Getting Started

### 🧱 Build the project

Make sure you have a C++17-compatible compiler.

```bash
make        # Build the project
./calculator  # Run the calculator
```

### 🧼 Clean build

```bash
make clean  # Removes the compiled executable
```

---

## 🧠 Example Usage

```
--- Calculator Menu ---
1. Perform Operation
2. Undo
3. Redo
4. View History
5. Exit
Choose an option: 1
Enter first operand: 10
Enter operator (+, -, *, /, %, ^): *
Enter second operand: 3
Result: 30
```

```
--- Calculator Menu ---
4. View History
Recent Operations:
1. 10 * 3 = 30
```

---

## ↩️ Undo / Redo (Bonus Feature)

- Undo: Reverts the last performed operation and moves it to the redo stack
- Redo: Re-applies the last undone operation and adds it back to history
- **Note**: Calculator is stateless — undo/redo affects operation visibility, not a cumulative total

---

## 🔮 Future Improvements

- Real-time input validation
- Expression-based calculation (e.g., `3 + 4 * 2`)
- Memory store/recall functionality
- Persistent history saved via file I/O
- Cumulative state-based undo/redo

---
