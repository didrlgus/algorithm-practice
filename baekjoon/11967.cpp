// 불켜기
#include<bits/stdc++.h>
using namespace std;
int n,m,ret;
vector<pair<int,int>> v[105][105];
bool visited[105][105],light[105][105];
queue<pair<int,int>> q;
int dy[]={0,0,1,-1},dx[]={1,-1,0,0};
bool bfs(int y,int x) {
    visited[0][0]=true;
    light[0][0]=true;
    q.push({0,0});
    for(auto it:v[y][x]) {
        if(!light[it.first][it.second]) light[it.first][it.second]=true;
    }
    bool flag=false;
    while(!q.empty()) {
        tie(y,x)=q.front();q.pop();
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=n) continue;
            if(!visited[ny][nx]&&light[ny][nx]) {           // 인접정점의 불이 켜져 있는 경우 해당 방을 지날 수 있다
                visited[ny][nx]=true;
                for(auto it:v[ny][nx]) {
                    if(!light[it.first][it.second]) {       // 해당 정점의 인접정점에서 새로운 불이 켜지는 경우
                        light[it.first][it.second]=true;
                        flag=true;
                    }
                }
                q.push({ny,nx});
            }
        }
    }
    return flag;
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        a--;b--;c--;d--;
        v[a][b].push_back({c,d});
    }
    // 새로운 불빛이 켜질때마다 해당 정점을 건널 수 있는 지 bfs로 검사해야 함
    // (불이 켜지는 시점에 인접하지 않은 정점에서 불이 켜질 수 있기 때문)
    while(true) {    
        fill(&visited[0][0],&visited[0][0]+105*105,false);
        if(!bfs(0,0)) break;    // 새로운 불이 켜지지 않을 때까지 반복, 새로운 불이 켜지면 break
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) if(light[i][j]) ret++;
    }
    printf("%d\n",ret);
    return 0;
}