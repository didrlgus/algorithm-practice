// ???
#include<bits/stdc++.h>

using namespace std;

int n,m;
char arr[25][25];
bool visited[25][25];
bool check[110];

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

int mx=-987654321;

void dfs(int y,int x,int current) {
    mx=max(mx,current);

    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];

        if(ny<0||nx<0||ny>=n||nx>=m) continue;

        if(!visited[ny][nx] && !check[arr[ny][nx]]) {
            visited[ny][nx]=true;
            check[arr[ny][nx]]=true;

            dfs(ny,nx,current+1);

            visited[ny][nx]=false;
            check[arr[ny][nx]]=false;
        }
    }
}

int main() {

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }

    visited[0][0]=true;
    check[arr[0][0]]=true;
    dfs(0,0,1);
    printf("%d\n",mx);

    return 0;
}