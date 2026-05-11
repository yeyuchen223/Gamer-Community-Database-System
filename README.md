# Gamer Community Database System 🎮

## Overview
This project is a desktop Graphical User Interface (GUI) application developed using **C++** and the **Qt Framework**. It serves as a comprehensive database management system tailored for a gamer community. The application provides intuitive interfaces for user registration, member profile management, ranking displays, and backend SQL database interactions.

## Key Features
* **Member Management:** Add, update, and manage community members efficiently (`addmember.ui`, `updatemember.ui`).
* **Personal Dashboard:** Dedicated interfaces for users to view and edit their personal profiles and private settings (`myself.ui`, `privateui.ui`).
* **Ranking System:** Dynamic display of player leaderboards and community rankings (`rank.ui`).
* **Database Integration:** Seamless backend database connections for persistent data storage and querying (`stusql.cpp`).
* **Resource Management:** Centralized management of UI assets and images using the Qt Resource System (`picture.qrc`).

## Tech Stack
* **Language:** C++
* **UI Framework:** Qt (Qt Widgets)
* **Database:** SQL (via Qt SQL modules)
* **IDE:** Qt Creator

## Repository Structure
```text
.
├── together.pro        # Core Qt project configuration file
├── main.cpp            # Application entry point
├── mainwindow.cpp/h/ui # Main dashboard interface
├── member.cpp/h/ui     # Member management logic and UI
├── stusql.cpp/h        # Backend SQL database operations
└── picture.qrc         # Application image resources
```

## Getting Started

### Prerequisites
* **Qt Creator** (Qt 5 or Qt 6 recommended)
* A compatible C++ compiler (e.g., MinGW for Windows, or MSVC)

### How to Run
1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/yeyuchen223/Gamer-Community-Database-System.git](https://github.com/yeyuchen223/Gamer-Community-Database-System.git)
    cd Gamer-Community-Database-System/together
    ```

2.  **Open the Project:**
    Launch **Qt Creator** and open the `together.pro` project file.

3.  **Configure the Build:**
    Select your appropriate desktop kit (e.g., Desktop Qt 5.x.x MinGW 64-bit) when prompted by Qt Creator.

4.  **Build and Run:**
    Press `Ctrl + R` (or click the green **Play** button in the bottom left corner of Qt Creator) to compile and launch the application.
