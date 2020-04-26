// 자물쇠와 열쇠
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int keySize,lockSize;

void rotate(vector<vector<int>> &key) {
    vector<vector<int>> tmp(keySize,vector<int>(keySize,0));

    for(int i = 0; i < keySize; i++){
        for(int j = 0; j < keySize; j++){
            //temp[i][j] = key[j][m - i - 1];           // 반시계방향
            tmp[i][j] = key[keySize - j - 1][i];        // 시계방향
        }
    }
    key=tmp;
    return;
}

bool checkKey(int r,int c,vector<vector<int>> key, vector<vector<int>> board) {

    for(int i=r;i<r+keySize;i++) {
        for(int j=c;j<c+keySize;j++) {
            board[i][j]+=key[i-r][j-c];
        }
    }

    for(int i=keySize-1;i<=board.size()-keySize;i++) {
        for(int j=keySize-1;j<=board.size()-keySize;j++) {
            if(board[i][j]==1) continue;

            return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    keySize=key.size(),lockSize=lock.size();
    int boardSize=(keySize-1)*2+lockSize;
    
    vector<vector<int>> board(boardSize,vector<int>(boardSize,0));

    // lock 초기화
    for(int i=keySize-1;i<=boardSize-keySize;i++) {
        for(int j=keySize-1;j<=boardSize-keySize;j++) {
            board[i][j]=lock[i-keySize+1][j-keySize+1];
        }
    }
    
    for(int r=0;r<4;r++) {
        for(int i=0;i<=boardSize-keySize;i++) {
            for(int j=0;j<=boardSize-keySize;j++) {
                if(checkKey(i,j,key,board)) {
                    return true;
                }
            }
        }

        rotate(key);
    }

    return answer;
}

int main() {

    vector<vector<int>> key={{0,0,0},{1,0,0},{0,1,1}}, lock={{1,1,1},{1,1,0},{1,0,1}};
    bool result=solution(key,lock);
    printf("%d\n",result);

    return 0;
}