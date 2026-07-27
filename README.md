# Rock Paper Scissors

![C++](https://img.shields.io/badge/Language-C%2B%2B-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Status](https://img.shields.io/badge/Status-Completed-success)

A console-based Rock Paper Scissors game written in C++ featuring robust input validation, score tracking, and replay support.

## 📥 Download

[![Download](https://img.shields.io/badge/Download-Latest%20Release-success?style=for-the-badge)](https://github.com/YOUR_USERNAME/cpp-rock-paper-scissors/releases/latest)

Download the latest Windows executable from the latest GitHub Release, or build the project yourself by following the instructions below.

---

## Table of Contents

- [Features](#features)
- [Gameplay Preview](#gameplay-preview)
- [Project Structure](#project-structure)
- [Building](#building)
- [What I Learned](#what-i-learned)
- [Future Improvements](#future-improvements)
- [License](#license)

---

## Features

- 🎮 Classic Rock, Paper, Scissors gameplay
- ✅ Robust input validation
- 🔤 Case-insensitive input
- 🏆 Live score tracking
- 🔁 Replay support
- 📁 Modular C++ program using multiple functions

---

## Gameplay Preview

### Starting a Match

At the beginning of every match, the player chooses how many points are required to win. The game validates the input before starting.

![Starting a Match](screenshots/start.png)

---

### Input Validation

The game rejects invalid inputs and asks the player to try again. Inputs are also case-insensitive, allowing entries such as `Rock`, `ROCK`, or `rock`.

![Input Validation](screenshots/input%20validation.png)

---

### Gameplay and Score Tracking

Each round displays the player's and computer's choices, announces the winner of the round, and updates the scoreboard until one side reaches the required number of points.

![Gameplay](screenshots/stats.png)

---

### Match Complete

Once the required score has been reached, the game announces the winner and offers the option to immediately play another match.

![Victory Screen](screenshots/victory.png)

---

## Project Structure

```text
cpp-rock-paper-scissors/
│
├── screenshots/
│   ├── start.png
│   ├── input-validation.png
│   ├── stats.png
│   └── victory.png
│
├── src/
│   └── main.cpp
│
├── README.md
├── LICENSE
└── .gitignore
```

---

## Building

Compile using g++:

```bash
g++ src/main.cpp -o RockPaperScissors
```

### Windows

Run:

```bash
RockPaperScissors.exe
```

### Linux/macOS

Run:

```bash
./RockPaperScissors
```

---

## What I Learned

This project helped me practice:

- Input validation
- Passing variables by reference (`&`)
- Range-based for loops (for each)
- Switch statements

---

## Future Improvements

- 🎨 Colored console output
- 📊 Match statistics
- 📂 Split the project into multiple source and header files
- 🧩 Object-oriented design

---

## License

This project is licensed under the MIT License.
