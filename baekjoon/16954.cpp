// 움직이는 미로 탈출
#include<bits/stdc++.h>
using namespace std;
char arr[10][10];
int n=8,ey=0,ex=7,dy[]={0,0,0,1,-1,1,1,-1,-1},dx[]={0,1,-1,0,0,1,-1,-1,1};
bool visited[10][10];
queue<pair<int,int>> q;
void move() {
    memset(visited,0,sizeof(visited));
    int size=(int)q.size();
    while(size--) {
        int y=q.front().first,x=q.front().second;q.pop();
        if(arr[y][x]=='#') continue;
        if(y==ey&&x==ex) {
            printf("1\n");
            exit(0);
        }
        for(int i=0;i<9;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=n) continue;
            if(!visited[ny][nx]&&arr[ny][nx]!='#') {
                visited[ny][nx]=true;
                q.push({ny,nx});
            }
        }
    }
}
void wall_move() {
    for(int j=0;j<n;j++) arr[7][j]='.';
    for(int i=n-1;i>=1;i--) {
        for(int j=0;j<n;j++) {
            if(arr[i-1][j]=='#') {
                arr[i-1][j]='.';
                arr[i][j]='#';
            }
        }
    }
}
int main() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf(" %1c",&arr[i][j]);
    }
    q.push({7,0});
    while(true) {
        if(!q.size()) break;
        move();
        wall_move();
    }
    printf("0\n");
    return 0;
}