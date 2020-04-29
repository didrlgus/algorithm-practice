// 2468. 안전 영역
#include<bits/stdc++.h>

using namespace std;

int n;
int arr[105][105];
int visited[105][105];
int max_=-987987987;
int max2=-987987987;

int dy[]={0,0,1,-1}, dx[]={1,-1,0,0};

queue<pair<int,int>> q;

void bfs(int y,int x,int h) {
    // 시작점 방문
    visited[y][x]=1;
    q.push({y,x});

    while(!q.empty()) {
        tie(y,x)=q.front(); q.pop();

        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];

            if(ny<0 || ny>=n || nx<0 || nx>=n) continue;

            if(!visited[ny][nx] && arr[ny][nx]>h) {
                visited[ny][nx]=visited[y][x]+1;
                q.push({ny,nx});
            }
        }
    }
}

int main() {

    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
            max_=max(max_,arr[i][j]);           // 최대 높이
        }
    }

    for(int h=1;h<=max_;h++) {
        int cnt=0;
        bool flag=false;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(!visited[i][j] && arr[i][j]>h) {
                    cnt++;
                    bfs(i,j,h);
                    flag=true;
                }
            }
        }

        if(!flag) cnt=1;    // 물에 하나도 안잠기는 경우 영역=1

        max2=max(max2,cnt);
        fill(&visited[0][0],&visited[0][0]+105*105,0);
    }

    printf("%d\n",max2);

    return 0;
}