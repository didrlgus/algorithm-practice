// 컴백홈
#include<bits/stdc++.h>

using namespace std;

int n,m,k;
char arr[10][10];
bool visited[10][10];

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
int cnt;

void dfs(int current,int y,int x) {
    if(y==0 && x==m-1 && current==k) {
        cnt++;
        return;
    }

    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];

        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(!visited[ny][nx] && arr[ny][nx]=='.') {
            visited[ny][nx]=true;
            dfs(current+1,ny,nx);
            visited[ny][nx]=false;
        }
    }
}

int main() {

    scanf("%d %d %d",&n,&m,&k);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }

    visited[n-1][0]=true;
    dfs(1,n-1,0);
    printf("%d\n",cnt);

    return 0;
}