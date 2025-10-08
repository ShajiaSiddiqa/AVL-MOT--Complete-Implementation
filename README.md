
---

#  Adelson-Velsky and Landis Tree (AVL) - Middle Order Tree

This project implements a **AVL** in C++ with support for both **unbalanced (BST-style)** and **balanced (AVL-style)** insertions. It includes full functionality to insert, delete, search, traverse, rotate, compare trees, save to file and load from file.

---

##  Project Structure

```
.
├── MOT.h               # Header file for the MOT class
├── MOT.cpp             # Implementation of all member functions
├── main.cpp            # Menu-driven interface for testing the BST
├── README.md           # This file
```

---

## 🔧 Features Implemented

###  Tree Operations

* Insert values (Unbalanced)
* Insert values (Balanced - with AVL-like rotations)
* Delete node
* Search node
* Find in-order successor and predecessor
* Save tree
* Load tree

###  Tree Traversals & Views

* In-order Traversal
* Tree View (Sideways - rotated)
* Level-order (Top-down BFS)

###  Tree Stats

* Tree height
* Total nodes
* Recursive depth
* Layer count (via level-order traversal)

###  Tree Comparisons

* Compare two trees for:

  * Same height
  * Same node count
  * Exact structure and data match

 ### Save & Load
  * save the tree in preorder
  * Load the same balanced tree

---

##  How to Run

1. **Compile the program:**

```bash
g++ main.cpp MOT.cpp -o main
```

2. **Run the program:**

```bash
./main
```

3. **You’ll see a menu like this:**

```
====== BINARY TREE MENU ======
1. Insert (Unbalanced)
2. Insert (Balanced)
3. Delete an element
4. Search an element
5. Find Successor
6. Find Predecessor
7. Print Tree (Sideways)
8. Print Tree (Level Order)
9. Print Tree (In-Order)
10. Tree Stats (Height + Node Count)
11. Compare With Another Tree (Structure and Data)
0. Exit
```

---

##  Sample Run

```
Enter your choice: 1
How many values do you want to insert into the tree? 6

Enter 6 values:
Value 1: 22
Value 2: 66
Value 3: 55
Value 4: 44
Value 5: 99
Value 6: 5

✅ Tree built successfully!

========= In-Order Traversal =========
5 22 44 55 66 99 

========= Tree View (Sideways) =========
        99
    66
        55
            44
22
    5

========= Level-Order (Top Down) =========
22 
5 66 
55 99 
44 

========= Tree Stats =========
Height: 3
Total Nodes: 6
Depth (recursive): 4
Layer Count (level-order method): 4
```

---

##  Concepts Covered

* Binary Search Tree (BST)
* AVL Tree Rotation (LL, RR, LR, RL)
* Recursion
* Tree Traversals (DFS and BFS)
* Tree Height, Depth, Layer Calculation
* Tree Comparison

---

##  Use Case

This project can be used for:

* Interview preparation (BST practice)
* Visualizing tree operations
* Learning balanced vs unbalanced trees

---

