#include <bits/stdc++.h>

using namespace std;

int sum_board(array<array<int, 8>, 8> &board){
    int sum=0;
    for(int i=0; i<8; i++){
        for (int j=0; j<8; j++) {
            if(board[i][j]==1) sum++;
            // cout << board[i][j] << " ";
        }
        // cout << endl;
    }
    return sum;
}

void full_board(array<array<int, 8>, 8> &board){
    for(int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            board[i][j] = 1;
        }
    }
}

static const int KING = 2;
static const int QUEEN = 3;
static const int BISHOP = 4;
static const int KNIGHT = 5;
static const int ROOK = 6;
static const int WPAWN = 7;
static const int BPAWN = 8;

void king(int x, int y, array<array<int, 8>, 8> &board);
void knight(int x, int y, array<array<int, 8>, 8> &board);
void rook(int x, int y, array<array<int, 8>, 8> &board);
void bpawn(int x, int y, array<array<int, 8>, 8> &board);
void wpawn(int x, int y, array<array<int, 8>, 8> &board);
void bishop(int x, int y, array<array<int, 8>, 8> &board);
void queen(int x, int y, array<array<int, 8>, 8> &board);

int main(){

    array<array<int, 8>, 8> board;
    for (int j=0; j<8; j++) board[j] = {0, 0, 0, 0, 0, 0, 0, 0};
    string fen;
    int strindex;
    while(getline(cin,fen)){
        full_board(board);
        strindex = 0;
        for(int i=0; i<8; i++){
            for(int j=0; j<8 && strindex < static_cast<int>(fen.size()); j++){
                if(fen[strindex]=='8' && fen[strindex+1]=='/') {
                    strindex+=2;
                    break;
                }
                if(fen[strindex]=='/'){
                    strindex++;
                }

                switch(fen[strindex]){
                    case 'K':
                    case 'k':
                        board[i][j] = KING;
                    break;
                    case 'Q':
                    case 'q':
                        board[i][j] = QUEEN;
                    break;
                    case 'B':
                    case 'b':
                        board[i][j] = BISHOP;
                    break;
                    case 'N':
                    case 'n':
                        board[i][j] = KNIGHT;
                    break;
                    case 'R':
                    case 'r':
                        board[i][j] = ROOK;
                    break;
                    case 'P':
                        board[i][j] = WPAWN;
                    break;
                    case 'p':
                        board[i][j] = BPAWN;
                    break;
                    default:
                        j+= fen[strindex] - '0'-1;
                    break;
                }
                strindex++;
            }
        }
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                switch(board[i][j]){
                    case KING: king(i, j, board); break;
                    case QUEEN: queen(i, j, board); break;
                    case BISHOP: bishop(i, j, board); break;
                    case KNIGHT: knight(i, j, board); break;
                    case ROOK: rook(i, j, board); break;
                    case BPAWN: bpawn(i, j, board); break;
                    case WPAWN: wpawn(i, j, board); break;
                }
            }
        }

        cout << sum_board(board) << endl;
    }
    return 0;
}

void king(int x, int y, array<array<int, 8>, 8> &board){
    x--;
    y--;
    for(int i=0; i<3; i++){
        if((x+i) < 0) continue;
        if((x+i) >= 8) break;
        for(int j=0; j<3; j++){
            if((y+j)<0) continue;
            if((y+j) >= 8) break;
            board[x+i][y+j] = board[x+i][y+j] == 1 ? 0 : board[x+i][y+j];
        }
    }
    
}


void knight(int x, int y, array<array<int, 8>, 8> &board){
    board[x][y]=KNIGHT;
    y-=2;
    if(y>=0){
        if((x-1)>=0 && board[x-1][y]==1) board[x-1][y] = 0;
        if((x+1)<8 && board[x+1][y]==1) board[x+1][y] = 0;
    }
    y++;
    if(y>=0){
        if((x-2)>=0 && board[x-2][y]==1) board[x-2][y] = 0;
        if((x+2)<8 && board[x+2][y]==1) board[x+2][y] = 0;
    }
    y+=2;
    if(y<8){
        if((x-2)>=0 && board[x-2][y]==1) board[x-2][y] = 0;
        if((x+2)<8 && board[x+2][y]==1) board[x+2][y] = 0;
    }
    y++;
    if(y<8){
        if((x-1)>=0 && board[x-1][y]==1) board[x-1][y] = 0;
        if((x+1)<8 && board[x+1][y]==1) board[x+1][y] = 0;
    }
}

void rook(int x, int y, array<array<int, 8>, 8> &board){
    for(int i=1; i<8 && board[x+i][y]<=1 && x+i<8; i++){
        board[x+i][y] = 0;
    }
    for(int i=1; i<8 && board[x-i][y]<=1 && x-i>=0; i++){
        board[x-i][y] = 0;
    }
    for(int i=1; i<8 && board[x][y+i]<=1 && y+i<8; i++){
        board[x][y+i] = 0;
    }
    for(int i=1; i<8 && board[x][y-i]<=1 && y-i>=0; i++){
        board[x][y-i] = 0;
    }
}

void bpawn(int x, int y, array<array<int, 8>, 8> &board){
    x++;
    if(x<8){
        if((y-1)>=0 && board[x][y-1]==1) board[x][y-1] = 0;
        if((y+1)< 8 && board[x][y+1]==1) board[x][y+1] = 0;
    }
}

void wpawn(int x, int y, array<array<int, 8>, 8> &board){
    x--;
    if(x<8){
        if((y-1)>=0 && board[x][y-1]==1) board[x][y-1] = 0;
        if((y+1)< 8 && board[x][y+1]==1) board[x][y+1] = 0;
    }
}

void bishop(int x, int y, array<array<int, 8>, 8> &board){
    for(int i=1; i<8 && x-i>=0 && y-i>=0 && board[x-i][y-i]<=1; i++){
        board[x-i][y-i] = 0;
    }

    for(int i=1; i<8 && x-i>=0 && y+i<8 && board[x-i][y+i]<=1; i++){
        board[x-i][y+i] = 0;
    }

    for(int i=1; i<8 && x+i<8 && y+i<8 && board[x+i][y+i]<=1; i++){
        board[x+i][y+i] = 0;
    }

    for(int i=1; i<8 && x+i<8 && y-i>=0 && board[x+i][y-i]<=1; i++){
        board[x+i][y-i] = 0;
    }
}

void queen(int x, int y, array<array<int, 8>, 8> &board){
    bishop(x, y, board);
    rook(x, y, board);
}