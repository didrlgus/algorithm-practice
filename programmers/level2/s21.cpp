// 가장 큰 정사각형 찾기
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;

    if(board.size()==1) {
        for(int j=0;j<board[0].size();j++) {
            if(board[0][j]==1) return 1;
        }    
    }

    if(board[0].size()==1) {
        for(int i=0;i<board.size();i++) {
            if(board[i][0]==1) return 1;
        }
    } 

    for(int i=1;i<board.size();i++) {
        for(int j=1;j<board[i].size();j++) {
            if(board[i][j]==1) {
                board[i][j]=min(board[i-1][j-1],min(board[i-1][j],board[i][j-1]))+1;

                answer=max(answer,board[i][j]);
            }
        }
    }

    return pow(answer,2);
}

int main() {

    vector<vector<int>> board={{1},{1},{1},{1}};
    int result=solution(board);
    printf("%d\n",result);

    return 0;
}