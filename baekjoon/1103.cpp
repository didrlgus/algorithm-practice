// 게임
#include<bits/stdc++.h>

using namespace std;

int n,m;
char arr[55][55];
bool visited[55][55];
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
int dp[55][55];
int dfs(int y,int x) {
    if(arr[y][x]=='H') return 0;
    if(y<0||x<0||y>=n||x>=m) return 0;
    if(visited[y][x]) {
        printf("-1\n");
        exit(0);
    }
    if(dp[y][x]!=-1) return dp[y][x];
    int& ret=dp[y][x];
    
    visited[y][x]=true;
    for(int i=0;i<4;i++) {
        int val=arr[y][x]-'0';
        int ny=y+dy[i]*val,nx=x+dx[i]*val;
        ret=max(ret,dfs(ny,nx)+1);
    }
    visited[y][x]=false;
    return ret;
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }
    fill(&dp[0][0],&dp[0][0]+55*55,-1);
    printf("%d\n",dfs(0,0));
    return 0;
}