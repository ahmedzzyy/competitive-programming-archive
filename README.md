## **🚀 Competitive Programming Solutions**
A collection of my solutions to problems from **LeetCode, CodeForces, CodeChef, and more**. This repository is structured for **efficient compilation and execution** using **VS Code tasks and C++ build scripts**.

---

### **📂 Folder Structure**
```
📦 competitive-programming-archive
 ┣ 📂 LeetCode/
 ┃ ┣ 📂 TwoSum/
 ┃ ┃ ┗ 📜 TwoSum.cpp
 ┃ ┗ 📂 SomeOtherProblem/
 ┃   ┗ 📜 SomeOtherProblem.cpp
 ┣ 📂 CodeForces/
 ┣ 📂 CodeChef/
 ┣ 📂 templates/
 ┣ 📜 .vscode/tasks.json   # VS Code build tasks
 ┣ 📜 .gitignore
 ┣ 📜 README.md
```
- **Each problem is stored in its own folder** (named after the problem).  
- **All C++ solutions use `<problem_name>.cpp` inside each problem folder**.  
- **VS Code tasks enable easy compilation and debugging**.

---

## **🛠️ Setup Instructions**
### **1️⃣ Install Required Tools**
Make sure you have:
- C / C++ Compiler - *Recommended: GCC (MinGW for Windows)*
- Configured Code Editor - *Example: VS Code*
- GDB/LLDB for debugging (optional)

---

### **2️⃣ Clone the Repository**
```sh
git clone https://github.com/ahmedzzyy/competitive-programming-archive.git
cd competitive-programming-archive
```

---

### **🚀 Running & Compiling Code**
You can **compile and run C++ solutions manually** using the following commands.  

#### **1️⃣ Manual Compilation & Execution**
- **➡️ Debug Mode (`-DLOCAL`)**

For debugging and **file I/O redirection**, use `-DLOCAL`:  

```sh
g++ -std=c++17 -Wall -Wextra -Wshadow -DLOCAL path/to/file.cpp -o output
./output
```

💡 **What `-DLOCAL` Does:**  

When `-DLOCAL` is defined, `freopen("input.txt", "r", stdin);` and `freopen("output.txt", "w", stdout);` are enabled, allowing you to use **input.txt/output.txt** for I/O.

#### **➡️ Optimized Compilation (`-O2`)**

For faster execution (without debugging flags):  
```sh
g++ -std=c++17 -Wall -Wextra -Wshadow -O2 path/to/file.cpp -o output
./output
```

---

#### **2️⃣ Running with Custom Input/Output Files**
Instead of using `-DLOCAL`, you can manually redirect I/O:  
```sh
./output < input.txt > output.txt
```
This avoids modifying the code while still using file-based input/output.

---

#### **📌 Note for VS Code Users**
If you use **VS Code**, this repository includes a pre-configured **`tasks.json`** to make compilation easier.  
- Open any `main.cpp`
- Press **`Ctrl + Shift + B`** to compile automatically  

If needed, you can modify `.vscode/tasks.json` to adjust compiler flags.  

---

## **📝 Contribution Guidelines**  

This repository is primarily for **personal use**, but if you have useful additions, feel free to contribute.  

- If you find an issue or have a suggestion, **open an issue**.  
- If you want to add something, **create a pull request (PR)**.  
- No strict contribution rules—just keep the repo clean and useful.  

---

## **📜 License**
Not applicable. *(Personal Use Case)*

---

### **🎯 Happy Coding & Keep Grinding! 💪🔥**