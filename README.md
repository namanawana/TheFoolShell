# TheFoolShell

A lightweight Unix-like shell written in C++ that supports built-in commands and executes external programs using `fork()`, `execvp()`, and `wait()`.  
Built as part of the Makers event.

---

## Features

- Interactive shell loop
- Full command-line input using `getline()`
- External command execution with arguments
- Built-in commands
- Basic command history
- Custom prompt & startup banner
- Works on macOS/Linux

---

## Built-in Commands

| Command | Description |
|--------|-------------|
| `cd <dir>` | Change directory |
| `clear` | Clear the terminal screen |
| `history` | Show previously entered commands |
| `help` | Show list of supported commands |
| `exit` | Exit the shell |

---

## External Commands

Supports execution of any command available in system `PATH`, including:
ls, pwd, cat, date, whoami, gcc, python3, node, etc.
Arguments are supported as well, for example:
ls -l
cat notes.txt
gcc main.cpp -o main
## Implementation Details

- `getline()` used for full input parsing
- Commands tokenized using `stringstream` + `vector<string>`
- External commands run via:
  - `fork()` to create child process
  - `execvp()` to execute command
  - `wait()` to synchronize parent/child
- Built-ins handled directly by the shell without `execvp()`

---

## Installation & Running

Compile:

```bash
g++ myshell.cpp -o myshell
Run:

./myshell
Future Improvements:
Add pipe support using pipe() + dup2()
Add I/O redirection
Add job control
Persistent history stored to file
Color prompt / thematic improvements


Project Build, for Makers Event, IIT Roorkee 2026

