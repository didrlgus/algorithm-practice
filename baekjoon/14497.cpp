// 주난의 난
#include<bits/stdc++.h>

using namespace std;

int n,m;
int y2,x2;      // 범인의 위치

char arr[310][310];
bool visited[310][310];

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

bool bfs(int y,int x) {
    queue<pair<int,int>> q;
    visited[y][x]=true;
    q.push({y,x});

    while(!q.empty()) {
        tie(y,x)=q.front();
        q.pop();

        if(y==y2&&x==x2) return true;

        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];

            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(!visited[ny][nx] && arr[ny][nx]=='1') {
                visited[ny][nx]=true;       // 추후에 0에의해 또 지나치면 안되므로, 큐에도 넣지 않는다
                arr[ny][nx]='0';
            }
            if(!visited[ny][nx] && (arr[ny][nx]=='0' || arr[ny][nx]=='#')) {
                visited[ny][nx]=true;
                q.push({ny,nx});
            }
        }
    }
    return false;
}

int main() {
    int y1,x1;      // 주난의 위치
    scanf("%d %d",&n,&m);
    scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
    y1--; x1--;
    y2--; x2--;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }
    int t=0;
    while(true) {
        fill(&visited[0][0],&visited[0][0]+310*310,0);
        if(bfs(y1,x1)) break;
        t++;
    }
    
    printf("%d\n",t+1);

    return 0;
}