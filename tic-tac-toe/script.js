// Create a game board with a 3x3 grid
// Implement a function to check if a player has won

// Add click events for each cell in the grid

// Display the winner or a draw message
const gameBoard = document.getElementById('gameBoard');
const message = document.getElementById('message');
let board = [
    ['', '', ''],
    ['', '', ''],
    ['', '', '']
];
let currentPlayer = 'X';

function createBoard() {
    gameBoard.innerHTML = '';
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            const cell = document.createElement('div');
            cell.classList.add('cell');
            cell.dataset.row = i;
            cell.dataset.col = j;
            cell.addEventListener('click', handleCellClick);
            gameBoard.appendChild(cell);
        }
    }
}

function handleCellClick(event) {
    const row = event.target.dataset.row;
    const col = event.target.dataset.col;
    if (board[row][col] === '') {
        board[row][col] = currentPlayer;
        event.target.textContent = currentPlayer;
        if (checkWinner()) {
            message.textContent = `${currentPlayer} wins!`;
            gameBoard.removeEventListener('click', handleCellClick);
        } else if (board.flat().every(cell => cell !== '')) {
            message.textContent = 'It\'s a draw!';
        } else {
            currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
        }
    }
}

function checkWinner() {
    const winningCombinations = [
        [[0, 0], [0, 1], [0, 2]],
        [[1, 0], [1, 1], [1, 2]],
        [[2, 0], [2, 1], [2, 2]],
        [[0, 0], [1, 0], [2, 0]],
        [[0, 1], [1, 1], [2, 1]],
        [[0, 2], [1, 2], [2, 2]],
        [[0, 0], [1, 1], [2, 2]],
        [[0, 2], [1, 1], [2, 0]]
    ];
    return winningCombinations.some(combination => {
        return combination.every(([row, col]) => {
            return board[row][col] === currentPlayer;
        });
    });
}

createBoard();


