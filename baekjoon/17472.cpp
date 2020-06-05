#include<bits/stdc++.h>

using namespace std;

int n,m;
int arr[15][15];
bool visited[15][15];
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

void dfs(int y,int x,int num) {
    visited[y][x]=true;
    arr[y][x]=num;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];

        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(!visited[ny][nx]&&arr[ny][nx]) {
            arr[ny][nx]=num;
            dfs(ny,nx,num);
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    int num=1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]==1&&!visited[i][j]) {
                dfs(i,j,num++);
            }
        }
    }
    printf("\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}