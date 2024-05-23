#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class GameOfLife {
private:
    int rows;
    int cols;
    std::vector<std::vector<bool>> grid;
    
    // Function to count live neighbors for a given cell
    int countLiveNeighbors(int row, int col) {
        int count = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (!(i == 0 && j == 0)) { // Exclude the cell itself
                    int newRow = row + i;
                    int newCol = col + j;
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol]) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
    
public:
    // Constructor
    GameOfLife(int rows, int cols) : rows(rows), cols(cols) {
        // Initialize grid with random values
        std::srand(std::time(nullptr));
        grid.resize(rows, std::vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                grid[i][j] = std::rand() % 2 == 1;
            }
        }
    }
    
    // Function to update the grid for the next generation
    void update() {
        std::vector<std::vector<bool>> newGrid(rows, std::vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int liveNeighbors = countLiveNeighbors(i, j);
                if (grid[i][j]) {
                    // Any live cell with fewer than two live neighbors dies (underpopulation)
                    // Any live cell with more than three live neighbors dies (overpopulation)
                    newGrid[i][j] = (liveNeighbors == 2 || liveNeighbors == 3);
                } else {
                    // Any dead cell with exactly three live neighbors becomes a live cell (reproduction)
                    newGrid[i][j] = (liveNeighbors == 3);
                }
            }
        }
        grid = newGrid;
    }
    
    // Function to print the grid
    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << (grid[i][j] ? "*" : " ") << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Define the size of the grid
    int rows = 10;
    int cols = 10;
    
    // Create the game object
    GameOfLife game(rows, cols);
    
    // Run the game for some generations
    for (int generation = 0; generation < 10; ++generation) {
        std::cout << "Generation " << generation << std::endl;
        game.print();
        game.update();
        std::cout << std::endl;
    }
    
    return 0;
}
