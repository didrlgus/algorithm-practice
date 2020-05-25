// 치즈
#include<bits/stdc++.h>

using namespace std;

int n,m,cnt,t,arr[110][110];
bool visited[110][110];
vector<pair<int,int>> cheese;
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

void dfs(int y,int x) {
    visited[y][x]=true;

    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];

        if(ny<0||nx<0||ny>=n||nx>=m) continue;

        if(!visited[ny][nx]&&arr[ny][nx]==0) dfs(ny,nx);
        else if(!visited[ny][nx]&&arr[ny][nx]==1) {
            visited[ny][nx]=true;
            cheese.push_back({ny,nx});
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==1) cnt++;
        }
    }
    while(cnt>0) {
        fill(&visited[0][0],&visited[0][0]+110*110,false);
        cheese.clear();
        t++;
        dfs(0,0);
        for(auto iter:cheese) arr[iter.first][iter.second]=0;
        cnt-=(int)cheese.size();
    }
    printf("%d\n%d\n",t,(int)cheese.size());
    return 0;
}