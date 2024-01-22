#include<bits/stdc++.h>
using namespace std;
#define ll long long
char board[10];
bool check[10];

void initialize()
{
    for(int i=0; i<9; i++)
    {
        board[i]='*';
        check[i]=false;
    }
}

void printBoard()
{
    for(int i=0; i<9; i++)
    {
        if(i%3==0)cout<<endl;
        cout<<board[i]<<" ";
    }
    cout<<endl;
}

bool checkWinner(char ch)
{
    for(int i=0; i<9; i+=3)
    {
        if(board[i]==board[i+1] && board[i]==board[i+2] && board[i] == ch) return true;
    }
    //ColumnCheck
    if(board[0]==board[3] && board[0]==board[6] && board[0] == ch) return true;
    if(board[1]==board[4] && board[1]==board[7] && board[1] == ch) return true;
    if(board[2]==board[5] && board[2]==board[8] && board[2] == ch) return true;

    //Diagonal
    if(board[0]==board[4] && board[0]==board[8] && board[0] == ch) return true;
    if(board[2]==board[4] && board[2]==board[6] && board[2] == ch) return true;

    return false;
}


int validMove()
{
    for(int i=0; i<9; i++)
    {
        if(check[i]==false)
        {
            return i;
        }
    }
}

bool checkgameOver()
{
    //RowWiseCheck
    for(int i=0; i<9; i+=3)
    {
        if(board[i]==board[i+1] && board[i]==board[i+2] && board[i] != '*') return true;
    }
    //ColumnCheck
    if(board[0]==board[3] && board[0]==board[6] && board[0] != '*') return true;
    if(board[1]==board[4] && board[1]==board[7] && board[1] != '*') return true;
    if(board[2]==board[5] && board[2]==board[8] && board[2] != '*') return true;

    //Diagonal
    if(board[0]==board[4] && board[0]==board[8] && board[0] != '*') return true;
    if(board[2]==board[4] && board[2]==board[6] && board[2] != '*') return true;

    return false;
}

void startGame(bool isMyMove)
{
    printBoard();
    if(checkgameOver())
    {
        return;
    }
    int trun = validMove();
    if(isMyMove)
    {
        board[trun] = 'X';
        check[trun]=true;
        startGame(false);
    }
    else
    {
        board[trun] = 'O';
        check[trun]=true;
        startGame(true);
    }
}

int main()
{
    initialize();
    printBoard();
    check[0]=true;
    board[0]='X';

    startGame(false);

    cout<<endl<<"Game over"<<endl;

    bool meWin = checkWinner('X');
    bool opponentWin = checkWinner('O');

    if(meWin) cout<<"I am winner"<<endl;
    else if(opponentWin) cout<<"Opponent is winner"<<endl;
    else cout<<"Draw"<<endl;

}
