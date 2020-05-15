// 로봇 청소기
#include<bits/stdc++.h>

using namespace std;

int n,m,r,c,dir;
int arr[55][55];
bool visited[55][55];
int cnt=1;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

bool flag2;

void dfs(int y,int x,int dir) {
    if(flag2) return;
    int ndir=dir;
    bool flag=false;
    // 현재 방향기준 네방향에서 청소할 수 있는 영역 탐색
    for(int i=0;i<4;i++) {
        ndir=ndir-1<0?3:ndir-1;

        int ny=y+dy[ndir],nx=x+dx[ndir];
        if(!visited[ny][nx] && arr[ny][nx]==0) {    // 탐색할 수 있는 경우
            flag=true;
            break;
        }
    }

    if(!flag) {                                 // 네 방향 모두 청소가 되어있거나 벽일 경우
        int back=(dir-2<0)?dir+2:dir-2;         // 뒤쪽방향
        int ny=y+dy[back],nx=x+dx[back];

        if(arr[ny][nx]==1) {                    // 뒤쪽이 벽일 경우
            flag2=true;
            return;
        } else {                                // 뒤쪽이 벽이 아닐 경우
            dfs(ny,nx,dir);                     // 바라보는 방향을 유지한 채로 후진
        }
    } else {                                    // 청소할 방향이 있는 경우
        int ny=y+dy[ndir],nx=x+dx[ndir];
        visited[ny][nx]=true;
        cnt++;
        dfs(ny,nx,ndir);
    }
}

int main() {

    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&r,&c,&dir);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
    }

    visited[r][c]=true;
    dfs(r,c,dir);
    printf("%d\n",cnt);

    return 0;
}