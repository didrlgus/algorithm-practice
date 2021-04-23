// [1차] 프렌즈4블록
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> erase_v;
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(true) {
        erase_v.clear();
        for(int i=0;i<m-1;i++) {
            for(int j=0;j<n-1;j++) {
                if(board[i][j]=='.') continue;
                int y1=i,x1=j+1;
                int y2=i+1,x2=j;
                int y3=i+1,x3=j+1;
                if(board[i][j]==board[y1][x1]&&board[y1][x1]==board[y2][x2]&&board[y2][x2]==board[y3][x3]) {
                    erase_v.push_back({i,j});
                    erase_v.push_back({y1,x1});
                    erase_v.push_back({y2,x2});
                    erase_v.push_back({y3,x3});
                }

            }
        }
        if(erase_v.empty()) break;
        for(auto it:erase_v) {
            if(board[it.first][it.second]!='.') {
                board[it.first][it.second]='.';
                answer++;
            }
        }
        for(int j=0;j<n;j++) {
            queue<int> q;
            for(int i=m-1;i>=0;i--) {
                if(board[i][j]!='.') {
                    q.push(board[i][j]);
                    board[i][j]='.';
                }
            }
            for(int i=m-1;i>=0;i--) {
                if(q.empty()) break;
                int f=q.front();q.pop();
                board[i][j]=f;
            }
        }
    }
    return answer;
}
int main() {
    int m=4,n=5;
    vector<string> board={"CCBDE", "AAADE", "AAABF", "CCBBF"};
    printf("%d\n",solution(m,n,board));
    return 0;
}