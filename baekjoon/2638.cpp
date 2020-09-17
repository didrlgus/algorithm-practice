// 치즈
#include<bits/stdc++.h>
using namespace std;
int n,m,dy[]={0,0,1,-1},dx[]={1,-1,0,0},cheese_cnt,ret;
bool arr[105][105],visited[105][105];
vector<pair<int,int>> v,vv;
void dfs(int y,int x) {
    visited[y][x]=true;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(!visited[ny][nx]&&arr[ny][nx]) {
            visited[ny][nx]=true;
            v.push_back({ny,nx});
        } else if(!visited[ny][nx]&&!arr[ny][nx]) dfs(ny,nx);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]) cheese_cnt++;
        }
    }
    while(cheese_cnt) {
        memset(visited,0,sizeof(visited));
        v.clear();
        vv.clear();
        dfs(0,0);
        for(auto it:v) {
            int y=it.first,x=it.second,cnt=0;
            for(int i=0;i<4;i++) {
                if(cnt>=2) break;
                int ny=y+dy[i],nx=x+dx[i];
                if(!arr[ny][nx]&&visited[ny][nx]) cnt++;
            }
            if(cnt>=2) {
                vv.push_back({y,x});
                cheese_cnt--;
            }
        }
        for(auto it:vv) arr[it.first][it.second]=false;
        ret++;
    }
    printf("%d\n",ret);
    return 0;
}