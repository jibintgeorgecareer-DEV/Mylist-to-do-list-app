**MyList** is a simple **command-line (CLI) to-do list application** developed completely using **C++**.
It allows users to manage daily tasks directly from the terminal using easy-to-understand commands.
All tasks are stored in a plain **text file (`.txt`)**, and the application performs operations like **add, edit, delete, search, and mark tasks as done or pending** by manipulating this file.
This project was created out of interest in **C++ programming and low-level computation concepts**, with a focus on **file handling, command-line interaction, and modular program design**.

---
✨ Features

* Add new tasks
* View all tasks
* Edit existing tasks
* Delete tasks
* Mark tasks as **Done** or **Pending**
* Undo task completion
* Search tasks using keywords
* Persistent storage using a `.txt` file
* Fully terminal-based interaction

---

## 🧾 Available Commands

| Command                   | Description                      |
| ------------------------- | -------------------------------- |
| `MyList add`              | Add a new task interactively     |
| `MyList list`             | Display all tasks                |
| `MyList view <id>`        | View a specific task by ID       |
| `MyList edit <id>`        | Edit an existing task            |
| `MyList delete <id>`      | Delete a task                    |
| `MyList complete <id>`    | Mark a task as completed         |
| `MyList undo <id>`        | Mark a completed task as pending |
| `MyList done`             | List all completed tasks         |
| `MyList pending`          | List all pending tasks           |
| `MyList search <keyword>` | Search tasks by keyword          |
| `MyList help`             | Display help information         |

---

## 📂 Project Folder Structure

```
MyList/
│
├── data/
│   └── tasks.txt        # Stores all task data
│
├── source_code/
│   ├── main.cpp         # Entry point & command handling
│   ├── commands.cpp     # Command logic implementation
│   ├── commands.h       # Command function declarations
│   ├── storage.cpp      # File read/write operations
│   ├── storage.h        # Storage function declarations
│   ├── task.cpp         # Task-related logic
│   └── task.h           # Task structure definition
│
└── README.md
```

---

## 🗂️ How Data Is Stored

* All tasks are stored in `data/tasks.txt`
* Each task is saved in a structured, readable format
* Tasks include:

  * ID
  * Title
  * Description
  * End Time
  * Registered Time
  * Status (Pending / Done)

The application reads, updates, and rewrites this file as needed to perform operations.

---

## ⚙️ Source Code Explanation

### 📁 `commands.cpp`

* Handles all **user commands**
* Implements logic for:

  * add
  * edit
  * delete
  * view
  * search
  * complete
  * undo
* Acts as a bridge between user input and file operations

### 📁 `storage.cpp`

* Responsible for **file handling**
* Reads tasks from `tasks.txt`
* Writes updated task data back to the file
* Uses temporary files for safe edit and delete operations

---

## 🔄 How the Application Works

1. User enters a command in the terminal (e.g., `MyList add`)
2. `main.cpp` parses the command-line arguments
3. Corresponding function in `commands.cpp` is called
4. `storage.cpp` reads or modifies the `tasks.txt` file
5. Updated data is saved back to the file
6. Output is displayed to the user in the terminal

---

## 🎯 Purpose of This Project

* Practice **C++ programming fundamentals**
* Learn **file handling and text-based data storage**
* Understand **command-line applications**
* Gain experience with **modular project structure**
* Build a real-world usable C++ project

---

## 🚀 Future Enhancements

* JSON-based storage
* AI-assisted task suggestions
* Statistics and task analytics
