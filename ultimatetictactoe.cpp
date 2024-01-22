#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll SUB_BOARD_SIZE = 3;
const ll MAIN_BOARD_SIZE = 3;

//Initialize the whole ultimate tic tac toe board
vector<vector<vector<char>>> ultimateMainBoard(MAIN_BOARD_SIZE, vector<vector<char>>(MAIN_BOARD_SIZE, vector<char>(SUB_BOARD_SIZE * SUB_BOARD_SIZE, ' ')));
vector<char>board1;
vector<vector<char>>board2;
char currentPlayer = 'X';

//To check if the given move is valid or not and check the cell is empty or not
bool isValidMove(ll boardRow, ll boardCol, ll cellRow, ll cellCol) {
    if (boardRow >= 0 && boardRow < MAIN_BOARD_SIZE &&
            boardCol >= 0 && boardCol < MAIN_BOARD_SIZE &&
            cellRow >= 0 && cellRow < SUB_BOARD_SIZE &&
            cellCol >= 0 && cellCol < SUB_BOARD_SIZE &&
            ultimateMainBoard[boardRow][boardCol][cellRow * SUB_BOARD_SIZE + cellCol] == ' ')
            return true;
    else return false;
}

//To print the whole board
void printBoard() {
    for (ll i = 0; i < MAIN_BOARD_SIZE; i++) {
        for (ll k = 0; k < SUB_BOARD_SIZE; k++) {
            for (ll j = 0; j < MAIN_BOARD_SIZE; j++) {
                for (ll l = 0; l < SUB_BOARD_SIZE; l++) {
                    char cellValue = ultimateMainBoard[i][j][k * SUB_BOARD_SIZE + l];
                    if (cellValue == ' ') {
                        cout<<"_ ";
                    } else {
                        cout<<cellValue<<" ";
                    }
                }
                cout<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

// to change the players move
bool makeMove(ll boardRow, ll boardCol, ll cellRow, ll cellCol) {
    if (isValidMove(boardRow, boardCol, cellRow, cellCol)) {
        ultimateMainBoard[boardRow][boardCol][cellRow * SUB_BOARD_SIZE + cellCol] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        return true;
    }
    return false;
}
//some implementation should be here
bool isGameOver() {
    return false;
}

//Winning condition for small board
bool winning_strategy_for_small_board(vector<char>& board1,ll cellRow, ll cellCol, ll SUB_BOARD_SIZE) {
    //For 3 Row
    if(board1[0]==board1[1]&&board1[1]==board1[2]&&board1[2]==board1[0]&&board1[0] !=' ') return true;
    else if(board1[3]==board1[4]&&board1[4]==board1[5]&&board1[5]==board1[3]&&board1[3] !=' ') return true;
    else if(board1[6]==board1[7]&&board1[7]==board1[8]&&board1[8]==board1[6]&&board1[6] !=' ') return true;
    else return false;

    //For 3 Col
    if(board1[0]==board1[3]&&board1[3]==board1[6]&&board1[6]==board1[0]&&board1[0] !=' ') return true;
    else if(board1[1]==board1[4]&&board1[4]==board1[7]&&board1[7]==board1[1]&&board1[1] !=' ') return true;
    else if(board1[2]==board1[5]&&board1[5]==board1[8]&&board1[8]==board1[2]&&board1[2] !=' ') return true;
    else return false;

    //For diagonal
    if(board1[0]==board1[4]&&board1[4]==board1[8]&&board1[8]==board1[0]&&board1[0]!=' ') return true;
    else if(board1[2]==board1[4]&&board1[4]==board1[6]&&board1[6]==board1[2]&&board1[2]!=' ') return true;

}
//winning condition for large board
bool winning_condition_for_main_board(vector<vector<char>>& board2, ll MAIN_BOARD_SIZE) {
    //For 3 Row
    //if(winning_strategy_for_small_board(board1, cellRow, cellCol, SUB_BOARD_SIZE)) {
    //}
   if(board2[0][0]==board2[0][1]&&board2[0][1]==board2[0][2]&&board2[0][2]==board2[0][0]&&board2[0][0] != ' ') return true;
   else if(board2[1][0]==board2[1][1]&&board2[1][1]==board2[1][2]&&board2[1][2]==board2[1][0]&&board2[1][0] != ' ') return true;
   else if(board2[2][0]==board2[2][1]&&board2[2][1]==board2[2][2]&&board2[2][2]==board2[2][0]&&board2[2][0] != ' ') return true;
   else return false;

   //For 3 Col
   if(board2[0][0]==board2[1][0]&&board2[1][0]==board2[2][0]&&board2[2][0]==board2[0][0]&&board2[0][0] != ' ') return true;
   else if(board2[0][0]==board2[1][0]&&board2[1][0]==board2[2][0]&&board2[2][0]==board2[0][0]&&board2[0][0] != ' ') return true;
   else if(board2[0][0]==board2[1][0]&&board2[1][0]==board2[2][0]&&board2[2][0]==board2[0][0]&&board2[0][0] != ' ') return true;
   else return false;

   //For diagonal purpose
   if(board2[0][0]==board2[1][1]&&board2[1][1]==board2[2][2]&&board2[2][2]==board2[0][0]&&board2[0][0]!=' ') return true;
   else if(board2[0][2]==board2[1][1]&&board2[1][1]==board2[2][0]&&board2[0][2]==board2[2][0]&&board2[0][0]!=' ') return true;
}

int main() {
    ll boardRow, boardCol, cellRow, cellCol;

    while (!isGameOver()) {
        printBoard();

        cout<<"Player "<<currentPlayer<<",Please enter your move:"<<endl;
        cout<<"Please Enter Your Ultimate Main Board coordinates (X Y): ";
        cin>>boardRow>>boardCol;
        cout<<"Please Enter Your Sub Cell Board coordinates (X Y): ";
        cin>>cellRow>>cellCol;

        if(makeMove(boardRow, boardCol, cellRow, cellCol)) {
            cout<<"Move accepted."<<endl;
        } else {
            cout<<"Invalid move.Please try again."<<endl;
        }
    }

    printBoard();
    cout << "Game over!" << endl;

    return 0;
}
int x,y,a,b;
    //char ch = 'O';
    while(subgrid_winner('X'))
    {
        cout<<"The winner is an AI chatbot.\n";
        return 0;
    }
    while(subgrid_winner('O'))
    {
        cout<<"The winner is Meeeee.\n";
        return 0;
    }
    while(!isgameover())
    {
        cout<<"Enter the position of the grid no: ";
        cin>>x>>y>>a>>b;
        if(main_grid[x][y][a][b] == '_')
        {
            makemove(x,y,a,b,'X');
            tictactoeprint();
            cout<<"Move accepted\n";
        }
        else if(sub_grid[x][y] != '_')
        {
            cout<<"Invalid move. Please take another input.\n";
        }

        else if(main_grid[x][y][a][b] != '_')
        {
            cout<<"Invalid move. Please take another input.\n";
        }
        else break;
    }

    if(subgrid_winner('X'))
    {
        cout<<"The winner is an AI chatbot.\n";
        return 0;
    }
    if(subgrid_winner('O'))
    {
        cout<<"The winner is Meeeee.\n";
        return 0;
    }
    else
    {
        cout<<"There is no one winner. The match is draw.\n";
        return 0;
    }

    = {{{{'_','_','_'},{'_','_','_'},{'_','_','_'}},
                               {{'_','_','_'},{'_','_','_'},{'_','_','_'}},
                               {{'_','_','_'},{'_','_','_'},{'_','_','_'}}},
                               {{{'_','_','_'},{'_','_','_'},{'_','_','_'}},
                               {{'_','_','_'},{'_','_','_'},{'_','_','_'}},
                               {{'_','_','_'},{'_','_','_'},{'_','_','_'}}},
                               {{{'_','_','_'},{'_','_','_'},{'_','_','_'}},
                               {{'_','_','_'},{'_','_','_'},{'_','_','_'}},
                               {{'_','_','_'},{'_','_','_'},{'_','_','_'}}},};
