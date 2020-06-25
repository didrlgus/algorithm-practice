// 레이저 통신
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[105][105],visited[105][105],dy[]={0,0,1,-1},dx[]={1,-1,0,0};
vector<pair<int,int>> v;
queue<pair<int,int>> q;
void bfs(int y,int x) {
    q.push({y,x});
    while(!q.empty()) {
        tie(y,x)=q.front();q.pop();
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            while(ny>=0&&nx>=0&&ny<n&&nx<m&&arr[ny][nx]!='*') {
                if(!visited[ny][nx]) {
                    visited[ny][nx]=visited[y][x]+1;
                    q.push({ny,nx});
                }
                ny+=dy[i];nx+=dx[i];
            }
        }
    }    
}   
int main() {
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf(" %1c",&arr[i][j]);
            if(arr[i][j]=='C') v.push_back({i,j});
        }
    }
    bfs(v[0].first,v[0].second);
    printf("%d\n",visited[v[1].first][v[1].second]-1);
    return 0;
}