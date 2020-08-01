// ???
#include<bits/stdc++.h>
using namespace std;
int n,m,dy[]={0,0,1,-1},dx[]={1,-1,0,0};
char arr[25][25];
int dfs(int y,int x,int visited) {
    int ret=0;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(visited&(1<<(arr[ny][nx]-'A'))) continue;
        ret=max(ret,dfs(ny,nx,visited|(1<<(arr[ny][nx]-'A')))+1);
    }   
    return ret;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }
    printf("%d\n",dfs(0,0,1<<(arr[0][0]-'A'))+1);
    return 0;
}