// 무기 공학
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[10][10],ret;
bool visited[10][10];
int getScore(int y,int x,int type) {
    if(type==0) return arr[y][x]*2+arr[y][x+1]+arr[y+1][x];
    else if(type==1) return arr[y][x]*2+arr[y][x-1]+arr[y-1][x];
    else if(type==2) return arr[y][x]*2+arr[y-1][x]+arr[y][x+1];
    else return arr[y][x]*2+arr[y][x-1]+arr[y+1][x];
}
void dfs(int y,int x,int sum) {
    if(y==n) {
        ret=max(ret,sum);
        return;
    }
    if(x==m) {
        dfs(y+1,0,sum);
        return;
    }
    if(!visited[y][x]) {
        if(x+1<m&&y+1<n&&!visited[y][x+1]&&!visited[y+1][x]) {
            visited[y][x]=true;
            visited[y][x+1]=true;
            visited[y+1][x]=true;
            dfs(y,x+1,sum+getScore(y,x,0));
            visited[y][x]=false;
            visited[y][x+1]=false;
            visited[y+1][x]=false;
        }
        if(x-1>=0&&y-1>=0&&!visited[y][x-1]&&!visited[y-1][x]) {
            visited[y][x]=true;
            visited[y][x-1]=true;
            visited[y-1][x]=true;
            dfs(y,x+1,sum+getScore(y,x,1));
            visited[y][x]=false;
            visited[y][x-1]=false;
            visited[y-1][x]=false;
        }
        if(x+1<m&&y-1>=0&&!visited[y-1][x]&&!visited[y][x+1]) {
            visited[y][x]=true;
            visited[y-1][x]=true;
            visited[y][x+1]=true;
            dfs(y,x+1,sum+getScore(y,x,2));
            visited[y][x]=false;
            visited[y-1][x]=false;
            visited[y][x+1]=false;
        }
        if(x-1>=0&&y+1<n&&!visited[y][x-1]&&!visited[y+1][x]) {
            visited[y][x]=true;
            visited[y][x-1]=true;
            visited[y+1][x]=true;
            dfs(y,x+1,sum+getScore(y,x,3));
            visited[y][x]=false;
            visited[y][x-1]=false;
            visited[y+1][x]=false;
        }
    }
    dfs(y,x+1,sum);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
    }
    dfs(0,0,0);
    printf("%d\n",ret);
    return 0;
}