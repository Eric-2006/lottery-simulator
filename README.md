# Lottery Simulator

A technical implementation of a betting-based "Guess the Number" game developed in C. This project demonstrates foundational programming concepts such as random number generation, input validation, and game loop logic.

## The Game Logic

The simulator generates a secret number between **0 and 1000**. The player must guess it, but every attempt has a cost that doubles after each failure:

* **Initial cost:** 1€
* **Winning prize:** 64€
* **Cost progression:** 1€, 2€, 4€, 8€, 16€, 32€...
* **Strategic Limit:** The game automatically stops a round if the next guess costs more than the potential prize (64€), preventing the player from guaranteed losses.

## Key Features

* **Dynamic Betting System:** Implements an exponential cost increase ($2^n$).
* **Input Validation:** Handles out-of-range numbers and offers a clean exit mid-game.
* **User Experience:** Provides real-time feedback (higher/lower) and tracks the player's total balance across multiple rounds.
* **Academic Context:** Originally developed as part of my Computer Science degree (Programació I) to practice control structures and standard I/O in C.

## Technologies Used

* **Language:** C++ (using C-style procedural paradigm)
* **Compiler:** GCC / G++
* **Libraries:** `stdio.h`, `stdlib.h`, `time.h`

## How to Run

1.  **Clone the repository:**
    ```bash
    git clone git@github.com:Eric-2006/lottery-simulator.git
    ```
2.  **Compile the code:**
    ```bash
    gcc -o lottery_sim main.c
    ```
3.  **Execute the program:**
    ```bash
    ./lottery_sim
    ```

## Technical Note (Language)
The source code, variable names, and internal comments are written in **Catalan**, as it was an academic project for University of Lleida (Catalonia) as part of the **Computer Science degree (Programació I, 2024-2025)**. This documentation is provided in English for universal portfolio visibility.

---
**Developed by:** Eric Buenavida Crespo.