// 백조의 호수
#include<bits/stdc++.h>
using namespace std;
int n,m,ret,sy,sx,ey,ex,dy[]={0,0,1,-1},dx[]={1,-1,0,0};
char arr[1505][1505];
vector<pair<int,int>> swan;
bool water_visited[1505][1505],swan_visited[1505][1505];
queue<pair<int,int>> water_q,swan_q;
bool swan_move() {
    int y,x;
    queue<pair<int,int>> tmp_q;
    while(!swan_q.empty()) {
        tie(y,x)=swan_q.front();swan_q.pop();
        if(y==ey&&x==ex) return true;
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(!swan_visited[ny][nx]&&arr[ny][nx]=='.') {
                swan_visited[ny][nx]=true;
                swan_q.push({ny,nx});
            }
            if(!swan_visited[ny][nx]&&arr[ny][nx]=='X') {
                swan_visited[ny][nx]=true;
                tmp_q.push({ny,nx});
            }
        }
    }
    swan_q=tmp_q;
    return false;
}
void water_spread() {
    int y,x;
    queue<pair<int,int>> tmp_q;
    while(!water_q.empty()) {
        tie(y,x)=water_q.front();water_q.pop();
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(!water_visited[ny][nx]&&arr[ny][nx]=='X') {
                water_visited[ny][nx]=true;
                tmp_q.push({ny,nx});
                arr[ny][nx]='.';
            }
        }
    }
    water_q=tmp_q;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf(" %1c",&arr[i][j]);
            if(arr[i][j]=='L') {
                swan.push_back({i,j});
                arr[i][j]='.';
            }
            if(arr[i][j]=='.') {
                water_visited[i][j]=true;
                water_q.push({i,j});
            }
        }
    }
    swan_q.push({swan.front().first,swan.front().second});
    ey=swan.back().first,ex=swan.back().second;
    while(true) {
        if(swan_move()) break;
        water_spread();
        ret++;
    }
    printf("%d\n",ret);
    return 0;
}