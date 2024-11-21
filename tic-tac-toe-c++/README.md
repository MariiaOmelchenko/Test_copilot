# Tic-Tac-Toe

This is a simple Tic-Tac-Toe game implemented using C++.

## Project Structure

tic-tac-toe/ ├── main.cpp ├── README.md └── .vscode/ ├── launch.json └── tasks.json

- `main.cpp`: The main C++ file that contains the game logic.
- `README.md`: This file, which provides information about the project.
- `.vscode/launch.json`: Configuration file for debugging with Visual Studio Code.
- `.vscode/tasks.json`: Configuration file for building the project with Visual Studio Code.

## How to Play

1. Compile the code using a C++ compiler (e.g., `g++`).
2. Run the compiled executable.
3. The game will prompt players to enter their moves (row and column).
4. The game alternates between player 'X' and player 'O'.
5. The game will display a message when a player wins or if the game ends in a draw.

## Game Logic

- The game board is represented by a 3x3 grid.
- Players take turns entering their moves by specifying the row and column.
- The game checks for a winner after each move by evaluating all possible winning combinations (rows, columns, and diagonals).
- If all cells are filled and no player has won, the game ends in a draw.

## Debugging

To debug the game using Visual Studio Code:

1. Ensure you have a C++ compiler installed (e.g., `g++`).
2. Install the C++ extension for Visual Studio Code.
3. Configure the `launch.json` and `tasks.json` files in the `.vscode` folder.
4. Set breakpoints in `main.cpp` where you want to pause execution.
5. Press `F5` to start debugging.

## Future Improvements

- Add a graphical user interface (GUI) for the game.
- Implement a reset button to start a new game.
- Add AI to play against the computer.
- Write unit tests for the game logic.

## License

This project is open-source and available under the MIT License.
