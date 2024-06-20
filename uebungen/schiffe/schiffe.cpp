#include <iostream>
#include <windows.h>

// Define colors for different states
enum Color {
    WHITE = 15,
    LIGHT_BLUE = 11,
    RED = 12,
    BLACK = 0
};

void setConsoleColor(int background, int text) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (background << 4) | text);
}

void draw_board(int board[10][10]) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            setConsoleColor(board[i][j], board[i][j] == BLACK ? WHITE : BLACK);
            std::cout << "    ";
        }
        std::cout << std::endl;
        for (int j = 0; j < 10; ++j) {
            setConsoleColor(board[i][j], board[i][j] == BLACK ? WHITE : BLACK);
            std::cout << "    ";
        }
        std::cout << std::endl;
    }

    // Reset to default color
    setConsoleColor(0, 15);
    std::cout << std::endl;
}

int main() {
    // Set up the console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD saved_attributes = consoleInfo.wAttributes;

    // Create the board and set initial colors
    int board[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            board[i][j] = WHITE; // Initialize with white background
        }
    }

    // Example changes to the board
    board[1][1] = LIGHT_BLUE; // "Ins Wasser geschossen"
    board[2][2] = RED;        // Treffer
    board[3][3] = BLACK;      // Treffer und versenkt

    // Draw the board
    draw_board(board);

    // Wait for user input before exiting
    std::cin.get();

    // Restore original console colors
    SetConsoleTextAttribute(hConsole, saved_attributes);
    return 0;
}

