// 토마토
#include<bits/stdc++.h>
using namespace std;
int m,n,h,arr[105][105][105],ret,z_cnt;
struct p {
    int y,x,z;
};
queue<p> q;
int dy[]={0,0,1,-1,0,0};
int dx[]={1,-1,0,0,0,0};
int dz[]={0,0,0,0,1,-1};
bool visited[105][105][105];
void bfs() {
    int size=q.size();
    while(size--) {
        p f=q.front();q.pop();
        for(int i=0;i<6;i++) {
            int ny=f.y+dy[i],nx=f.x+dx[i],nz=f.z+dz[i];
            if(ny<0||nx<0||nz<0||ny>=n||nx>=m||nz>=h) continue;
            if(!visited[ny][nx][nz]&&!arr[ny][nx][nz]) {
                visited[ny][nx][nz]=true;
                q.push({ny,nx,nz});
                z_cnt--;
            }
        }
    }
}
int main() {
    scanf("%d %d %d",&m,&n,&h);
    for(int k=0;k<h;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                scanf("%d",&arr[i][j][k]);
                if(arr[i][j][k]==1) {
                    q.push({i,j,k});
                    visited[i][j][k]=true;
                } else if(arr[i][j][k]==0) z_cnt++;
            }
        }
    }
    while(!q.empty()) {
        if(!z_cnt) break;
        bfs();
        ret++;
    }
    printf("%d\n",!z_cnt?ret:-1);
    return 0;
}