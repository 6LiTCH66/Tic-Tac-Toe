#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int COLUMN = 3;
const int ROW = 3;

int checkInput(string text);
char gameBoard[ROW][COLUMN] {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
};

class TicTacToe{
private:
    int position;
    int player;
    char character;
    char board[ROW][COLUMN];
public:
    TicTacToe(){
        createBoard();
    }

    void createBoard(){
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COLUMN; j++) {
                board[i][j] = gameBoard[i][j];
            }
        }
    }

    void printBoard(){
        cout << "|---||---||---|\n";
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COLUMN; j++) {
                cout << "| " << board[i][j] << " |";
            }
            cout << endl;
            cout << "|---||---||---|\n";
        }
    }

    void getCharacter(){
        while (true){
            player = checkInput("1. X\n2. O\n");
            if(player == 1){
                character = 'X';
                return;
            }
            else if(player == 2){
                character = 'O';
                return;
            }
        }

    }

    void updateBoard(){
        srand( (unsigned)time(NULL) );
        switch (position) {
            case 1:
                board[0][0] = character;
                printBoard();
                break;
            case 2:
                board[0][1] = character;
                printBoard();
                break;
            case 3:
                board[0][2] = character;
                printBoard();
                break;
            case 4:
                board[1][0] = character;
                printBoard();
                break;
            case 5:
                board[1][1] = character;
                printBoard();
                break;
            case 6:
                board[1][2] = character;
                printBoard();
                break;
            case 7:
                board[2][0] = character;
                printBoard();
                break;
            case 8:
                board[2][1] = character;
                printBoard();
                break;
            case 9:
                board[2][2] = character;
                printBoard();
                break;
            default:
                break;
        }
        checkNextStep();
    }

    bool isFree(){
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COLUMN; j++) {
                if (string(1, board[i][j]) == to_string(position)){
                    return true;
                }
            }
        }
        return false;

    }

    void checkNextStep(){
        if(character == 'X'){
            character = 'O';
        }
        else if(character == 'O'){
            character = 'X';
        }
    }


    bool isWin(){
        //Horizontal Win
        if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X'){
            cout << "X is won the game" << endl;
            return true;
        }
        if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X'){
            cout << "X is won the game" << endl;
            return true;
        }
        if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'){
            cout << "X is won the game" << endl;
            return true;
        }


        //Vertical Win
        if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X'){
            cout << "X is won the game" << endl;
            return true;
        }

        if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X'){
            cout << "X is won the game" << endl;
            return true;
        }
        if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'){
            cout << "X is won the game" << endl;
            return true;
        }


        //Diagonal Wins
        if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
            cout << "X is won the game" << endl;
            return true;
        }

        if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
            cout << "X is won the game" << endl;
            return true;
        }


        //Horizontal Win
        if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'){
            cout << "O is won the game" << endl;
            return true;
        }

        if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'){
            cout << "O is won the game" << endl;
            return true;
        }

        if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'){
            cout << "O is won the game" << endl;
            return true;
        }


        //Vertical Win
        if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){
            cout << "O is won the game" << endl;
            return true;
        }

        if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){
            cout << "O is won the game" << endl;
            return true;
        }

        if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){
            cout << "O is won the game" << endl;
            return true;
        }


        //Diagonal Wins
        if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
            cout << "O is won the game" << endl;
            return true;
        }

        if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
            cout << "O is won the game" << endl;
            return true;
        }


        // Tie
        if(board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' &&
                board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
                board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9'){
            cout << "Its a tie" << endl;
            return true;
        }

        return false;
    }


    void startGame(){
        while (!isFree()){
            position = checkInput("Enter a slot number to place " + string(1,character) + " in:");
        }
        updateBoard();
    }


    void computerGame(){
        while (!isFree()){
            cout << "Enter a slot number to place " << character << " in:";
            cin >> position;

        }
        updateBoard();

        cout << endl;
        while (!isFree()){
            position = (rand() % 11) +1;
        }
        cout << "Computer\'s move:\n";
        updateBoard();

        cout << endl;

    }
};

int checkInput(string text){
    int ch;
    cout << text;
    cin >> setw(1) >>ch;

    while (!cin.good()){
        cout << "Invalid input. Try again.\n";

        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cout << text;
        cin >> setw(1) >> ch;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    return ch;

}

int main() {

    TicTacToe twoPlayers;
    TicTacToe againstComputer;

    cout << "Welcome to 3x3 Tic Tac Toe" << endl;
    int ch;

    do{
        twoPlayers.createBoard();
        againstComputer.createBoard();
        cout << "1. Play together.\n2. Play against computer.\n9. Exit the game.\n";
        ch = checkInput("Enter your number:");

        switch (ch) {
            case 1:
                cout << endl;
                twoPlayers.printBoard();
                twoPlayers.getCharacter();

                while (!twoPlayers.isWin()){
                    twoPlayers.startGame();
                }

                cout << endl;
                break;

            case 2:
                cout << endl;
                againstComputer.printBoard();
                againstComputer.getCharacter();

                while (!againstComputer.isWin()){
                    againstComputer.computerGame();
                }
                cout << endl;
                break;
        }

    } while (ch != 9);

    return 0;
}
