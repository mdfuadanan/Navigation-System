# 🗺️ City Grid Navigation System

A Graph-based Navigation and Shortest Path Finding System in **C**, developed for the **Data Structures Lab (Open-Ended Lab)**.

This program models a 3x3 city block grid as an undirected graph, utilizing **Breadth-First Search (BFS)** to calculate the shortest path and generate step-by-step navigation instructions between any two blocks.

---

## 📌 Features

- **📍 Default 3×3 Grid Map**: Pre-configured with 9 blocks (`A` through `I`) connected via horizontal streets and vertical roads.
- **🧭 Shortest Path Navigation (BFS)**: Computes the unweighted shortest path between source and destination blocks with step-by-step travel directions (including street and road names).
- **➕ Dynamic Path Addition**: Allows users to establish new bidirectional roads/streets between any two blocks.
- **❌ Dynamic Path Deletion**: Allows users to remove existing connections (simulating road closures or blockages).
- **🖥️ Interactive ASCII Menu**: Simple, intuitive command-line interface with real-time grid visualization.

---

## 🗺️ City Map Layout

The default navigation network is structured as a 3×3 grid:

```text
            <-Street 1->   
        A--------B--------C
        |        |        |
        |   <-Street 2->  |
Road 1  | Road 2 | Road 3 |
        D--------E--------F
        |        |        |
        |    <-Street 3-> |
        |        |        |
        G--------H--------I
    Current Default Map    
(Roads are in columns, Streets are in rows)
```

### Initial Connections

| Type | Connection | Connected Blocks |
| :--- | :--- | :--- |
| **Streets (Horizontal)** | `Street 1` | `A <-> B`, `B <-> C` |
| | `Street 2` | `D <-> E`, `E <-> F` |
| | `Street 3` | `G <-> H`, `H <-> I` |
| **Roads (Vertical)** | `Road 1` | `A <-> D`, `D <-> G` |
| | `Road 2` | `B <-> E`, `E <-> H` |
| | `Road 3` | `C <-> F`, `F <-> I` |

---

## 🧠 Data Structures & Algorithms

### 1. Graph Representation (Adjacency List)
- **Nodes/Blocks**: 9 blocks represented by characters `'A'` through `'I'`, mapped to zero-based indices `0` through `8` via `BTI()` (Block-to-Index) and `ITB()` (Index-to-Block).
- **Edge Structure (`E`)**:
  ```c
  typedef struct {
      int to;
      char path_name[10];
  } E;
  ```
- **Graph Storage**: A 2D array `matrix[B][M]` where each row holds the list of outgoing edges for that block, and `Enumber[B]` tracks the active edge count for each block.

### 2. Breadth-First Search (BFS) for Shortest Path
- **Algorithm**: BFS is implemented using an array-based FIFO Queue (`Q[]`) to explore the grid level by level.
- **Shortest Path Guarantee**: Because all edges have uniform weight (1 hop), BFS guarantees the minimum hop count to reach the destination.
- **Path Reconstruction**:
  - `P[B]`: Tracks parent nodes for path backtracking.
  - `Via[B][10]`: Tracks the specific street/road name taken to enter each node.
  - After reaching the target, the path is reconstructed in reverse and output in chronological order (`Start -> End`).

---

## 🛠️ Compilation & Execution

### Prerequisites
- GCC / MinGW / Clang / MSVC compiler

### Compile

Using GCC:
```bash
gcc "Navigation System.c" -o "Navigation System"
```

### Run

On Windows:
```cmd
"Navigation System.exe"
```

On Linux / macOS:
```bash
./"Navigation System"
```

---

## 🎮 User Menu & Usage Guide

When launched, the system displays the menu:

```text
***Navigation System***
1. Travel
2. Add path
3. Delete path
4. Exit program.
Enter:
```

### 1. Travel (Find Shortest Path)
Finds the shortest route between two blocks and outputs step-by-step directions.

**Example Input:**
```text
Enter: 1
Source Block: A
Destination Block: I
```

**Example Output:**
```text
Path:
At Block A
Go to Block B via Street 1
Go to Block C via Street 1
Go to Block F via Road 3
Go to Block I via Road 3
Arrived at Block I
```

### 2. Add Path
Creates a new bidirectional edge between two blocks.

**Example Input:**
```text
Enter: 2
Source Block: A
Destination Block: E
Path Name: Diagonal1
```

### 3. Delete Path
Removes a connection between two blocks (simulating road construction/closure).

**Example Input:**
```text
Enter: 3
Source Block: B
Destination Block: C
Path Name: Street 1
```

---

## 📂 File Structure

```text
.
├── Navigation System.c    # Main source code
├── Navigation System.exe  # Compiled executable
└── README.md              # Project documentation
```

---

## 👥 Course Information

- **Course**: Data Structures - Lab
- **Institution**: University of Liberal Arts Bangladesh (ULAB)
- **Assignment**: Open Ended Lab
