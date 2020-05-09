// 방문 길이
#include <bits/stdc++.h>
using namespace std;

bool visited[15][15][15][15];
int solution(string dirs) {
    int answer = 0;

    int y=5,x=5;    // 시작점
    for(int i=0;i<dirs.size();i++) {
        char c=dirs[i];

        if(c=='U') {
            if(y-1>=0) {
                if(!visited[y][x][y-1][x]) {
                    visited[y][x][y-1][x]=true;
                    visited[y-1][x][y][x]=true;
                    answer++;
                }
                y--;
            }
        } else if(c=='D') {
            if(y+1<=10) {
                if(!visited[y][x][y+1][x]) {
                    visited[y][x][y+1][x]=true;
                    visited[y+1][x][y][x]=true;
                    answer++;
                }
                y++;
            }
        } else if(c=='L') {
            if(x-1>=0) {
                if(!visited[y][x][y][x-1]) {
                    visited[y][x][y][x-1]=true;
                    visited[y][x-1][y][x]=true;
                    answer++;
                }
                x--;
            }
        } else if(c=='R') {
            if(x+1<=10) {
                if(!visited[y][x][y][x+1]) {
                    visited[y][x][y][x+1]=true;
                    visited[y][x+1][y][x]=true;
                    answer++;
                }
                x++;
            }
        }
    }

    return answer;
}

int main() {

    string dirs="LULLLLLLU";
    int result=solution(dirs);
    printf("%d\n",result);

    return 0;
}