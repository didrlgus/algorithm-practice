// 적록색약
#include<bits/stdc++.h>
using namespace std;
int n,dy[]={0,0,1,-1},dx[]={1,-1,0,0},ret1,ret2;
char arr[105][105];
bool visited[105][105],visited2[105][105];
void dfs(int y,int x,char ch) {
    visited[y][x]=true;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=n) continue;
        if(!visited[ny][nx]&&arr[ny][nx]==ch) dfs(ny,nx,ch);
    }
}
void dfs2(int y,int x,int check) {
    visited2[y][x]=true;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=n) continue;
        if(!visited2[ny][nx]&&((1<<(arr[ny][nx]-'A'))&check)) dfs2(ny,nx,check);
    }
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf(" %1c",&arr[i][j]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(!visited[i][j]) {
                ret1++;
                dfs(i,j,arr[i][j]);
            }
            if(!visited2[i][j]) {
                ret2++;
                int check=0;
                if(arr[i][j]=='R'||arr[i][j]=='G') check=(1<<('R'-'A'))|(1<<('G'-'A'));
                else check=1<<(arr[i][j]-'A');
                dfs2(i,j,check);
            }
        }
    }
    printf("%d %d\n",ret1,ret2);
    return 0;
}