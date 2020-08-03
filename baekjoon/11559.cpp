// Puyo Puyo
#include<bits/stdc++.h>
using namespace std;
int n=12,m=6,dy[]={0,0,1,-1},dx[]={1,-1,0,0},ret;
bool visited[15][10];
char arr[15][10];
vector<pair<int,int>> v;
void dfs(int y,int x,char c) {
    visited[y][x]=true;
    v.push_back({y,x});
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(!visited[ny][nx]&&arr[ny][nx]==c) dfs(ny,nx,c);
    }
}
int main() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }
    while(true) {
        bool flag=false;
        memset(visited,0,sizeof(visited));
        queue<char> q;
        for(int j=0;j<m;j++) {
            for(int i=n-1;i>=0;i--) {
                if(arr[i][j]!='.') {
                    q.push(arr[i][j]);
                    arr[i][j]='.';
                }
            }
            int idx=n-1;
            while(!q.empty()) {
                auto f=q.front();q.pop();
                if(arr[idx][j]=='.') arr[idx--][j]=f;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(arr[i][j]=='.') continue;
                if(!visited[i][j]) {
                    dfs(i,j,arr[i][j]);
                    if((int)v.size()>=4) {
                        flag=true;
                        for(auto it:v) arr[it.first][it.second]='.';
                    }
                    v.clear();
                }
            }
        }
        if(!flag) break;
        ret++;
    }
    printf("%d\n",ret);
    return 0;
}