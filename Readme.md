
# 🌀 Push\_swap

Push\_swap is a sorting algorithm visualizer and challenge project from the 42 Network's Common Core curriculum. It involves creating a program that sorts a list of integers using two stacks and a limited set of instructions, aiming for the fewest operations possible.

## 🧠 Project Summary

You must write two programs:

* **push\_swap**: Takes a list of integers and outputs a sequence of stack operations to sort them.
* **checker** (bonus): Takes a list of integers and a list of operations, and checks if the result is a correctly sorted stack.

---

## 🗂️ Project Structure

```
📁 push_swap/
├── src/                # Main source files
├── src_bonus/          # Bonus part (checker)
├── libft/              # Your own C library
├── ft_printf/          # Custom printf library
├── Makefile            # Project build rules
├── README.md           # You are here!
```

---

## ✅ Allowed Operations

| Operation | Description                                |
| --------: | ------------------------------------------ |
|     sa/sb | Swap the first 2 elements of a stack       |
|        ss | sa and sb at the same time                 |
|     pa/pb | Push top element from one stack to another |
|     ra/rb | Rotate stack up (first becomes last)       |
|        rr | ra and rb at the same time                 |
|   rra/rrb | Reverse rotate (last becomes first)        |
|       rrr | rra and rrb at the same time               |

---

## 💻 Usage

### Compile

```bash
make            # builds push_swap
make bonus      # builds checker
```

### Run

```bash
./push_swap 2 1 3 6 5 8
# Outputs operations to sort the stack
```

### Bonus Checker

```bash
./push_swap 3 2 1 | ./checker 3 2 1
# Will print OK if sorted, KO otherwise
```

---

## 📌 Rules & Restrictions

* Only these stack operations are allowed (see above)
* No memory leaks or undefined behavior
* Must use your own `libft` and custom `printf`
* Handle errors like duplicates, non-integers, and overflows

---

## 🚀 Goals

* Develop efficient sorting strategies for various input sizes
* Learn stack-based algorithms
* Practice optimizing performance and minimizing instruction count


