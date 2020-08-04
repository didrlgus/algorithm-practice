// 말이 되고픈 원숭이
#include<bits/stdc++.h>
using namespace std;
int k,n,m,arr[205][205],dy[]={0,0,1,-1},dx[]={1,-1,0,0},h_dy[]={-2,-2,-1,-1,1,1,2,2},h_dx[]={-1,1,-2,2,-2,2,-1,1};
struct p {
    int y,x,cnt;
};
queue<p> q;
bool visited[205][205][35];
int bfs(int y,int x,int cnt) {
    visited[y][x][cnt]=true;
    q.push({y,x,cnt});
    int level=0;
    while(!q.empty()) {
        int size=(int)q.size();
        while(size--) {
            y=q.front().y,x=q.front().x,cnt=q.front().cnt;q.pop();
            if(y==n-1&&x==m-1) return level;
            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];
                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                if(!visited[ny][nx][cnt]&&arr[ny][nx]!=1) {
                    visited[ny][nx][cnt]=true;
                    q.push({ny,nx,cnt});
                }
            }
            if(cnt>0) {
                for(int i=0;i<8;i++) {
                    int ny=y+h_dy[i],nx=x+h_dx[i];
                    if(ny<0||nx<0||ny>=n||nx>=m) continue;
                    if(!visited[ny][nx][cnt-1]&&arr[ny][nx]!=1) {
                        visited[ny][nx][cnt-1]=true;
                        q.push({ny,nx,cnt-1});
                    }
                }
            }
        }
        level++;
    }
    return -1;
}
int main() {
    scanf("%d%d%d",&k,&m,&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
    }
    printf("%d\n",bfs(0,0,k));
    return 0;
}