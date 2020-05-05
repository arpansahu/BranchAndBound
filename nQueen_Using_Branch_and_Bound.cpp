#include <iostream>
#include "cstring"
#include "iomanip"
using namespace std;

#define N 8
bool isSafe(int row,int no_Queens_column,int slashDiagonal[N][N],int backslashDiagonal[N][N],bool slashCodeLookUp [],bool backslashCodeLoopUp[],bool rowLookUp[]){
    if(slashCodeLookUp[slashDiagonal[row][no_Queens_column]] || backslashCodeLoopUp[backslashDiagonal[row][no_Queens_column]] || rowLookUp[row]) return false;
    return true;
}
bool solveNQueenUtil(int board[N][N],int no_Queens_column,int slashDiagonal[N][N],int backslashDiagonal[N][N],bool slashCodeLookUp [],bool backslashCodeLoopUp[],bool rowLookUp[]){
    if (no_Queens_column >= N) return true;

    for (int i = 0; i < N; ++i) {
        if(isSafe(i,no_Queens_column,slashDiagonal,backslashDiagonal,slashCodeLookUp,backslashCodeLoopUp,rowLookUp)){
            board[i][no_Queens_column] =  1;
            rowLookUp[i] = true;
            slashCodeLookUp[slashDiagonal[i][no_Queens_column]] = true;
            backslashCodeLoopUp[backslashDiagonal[i][no_Queens_column]] = true;

            if(solveNQueenUtil(board,no_Queens_column + 1,slashDiagonal,backslashDiagonal,slashCodeLookUp,backslashCodeLoopUp,rowLookUp)) return  true;

            board[i][no_Queens_column ] = 0;
            rowLookUp[i] = false;
            slashCodeLookUp[slashDiagonal[i][no_Queens_column]] = false;
            backslashCodeLoopUp[backslashDiagonal[i][no_Queens_column]] = false;

        }
    }
}

void nQueen(){
    int board[N][N];
    memset(board,0, sizeof board);

    //helper matrix
    int slashDiagonal[N][N];
    int backslashDiagonal[N][N];

    //arrays to tell which rows are occupied
    bool rowLookUp[N] = {false};

    //keep two arrya stwo tell which diagonals are occupied
    bool slashCodeLookUp[ 2 * N - 1] = {false};
    bool backslashCodeLoopUp[2 * N - 1] = {false};

    //inititalising of both helper matrix

    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
            slashDiagonal[r][c] = r + c, backslashDiagonal[r][c] = r - c + (N - 1);
    /*
     *  cout <<" slash matrix : \n";
     for (int i = 0; i <N ; ++i) {
         for (int j = 0; j < N; ++j) {
             cout<<setw(3) << slashDiagonal[i][j]<<" ";
         }cout <<"\n";
     }
     cout <<"Back slash matrix : \n";
     for (int i = 0; i <N ; ++i) {
         for (int j = 0; j < N; ++j) {
             cout<<setw(3) << backslashDiagonal[i][j]<<" ";
         }cout <<"\n";
     }

     */
    if(solveNQueenUtil(board,0,slashDiagonal,backslashDiagonal,slashCodeLookUp,backslashCodeLoopUp,rowLookUp) == false){
        printf("Solution does not exists");
        return ;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}

int main(){

    nQueen();
    return 0;
}
