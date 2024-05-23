# gameoflife
# Conway's Game of Life - C++ Implementation

## Overview
This project is a C++ implementation of Conway's Game of Life, a cellular automaton devised by mathematician John Conway. The game consists of a grid of cells that can be in one of two states: alive or dead. The state of each cell evolves through generations based on a set of simple rules.

## Features
- Random initialization of the grid.
- Evolution of the grid through generations based on predefined rules.
- Console-based visualization of each generation.

## Rules of the Game
1. Any live cell with fewer than two live neighbors dies (underpopulation).
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies (overpopulation).
4. Any dead cell with exactly three live neighbors becomes a live cell (reproduction).

## Code Structure
The project contains a single class, `GameOfLife`, which handles the initialization, updating, and printing of the game grid.


### Main Function
The `main` function sets up the game with a grid of size 10x10 and runs it for 10 generations, printing the state of the grid at each generation.

## How to Run

1. **Run the executable**:
    ```bash
    ./game_of_life
    ```

