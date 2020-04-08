// 2207. 벽 부수고 이동하기
#include<cstdio>
#include<queue>
#include<string>
#include<iostream>

using namespace std;

int n,m;
char a[1005][1005];

struct p {
    int y,x,b;
};

queue<p> q;

int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

// 벽을 뚫을 수 있는 지 없는지 판단하기 위해 3차원 배열 사용
int visited[1005][1005][2];

int bfs(int r,int c) {
    visited[r][c][1]=1;
    q.push({r,c,1});

    int level=1;

    while(!q.empty()) {
        int size=q.size();

        while(size--) {
            int y=q.front().y;
            int x=q.front().x;
            int b=q.front().b;

            q.pop();

            if(y==n-1 && x==m-1) return level;

            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];

                if(ny<0 || nx<0 || ny>=n || nx>=m) continue;

                // b가 1이면 아직 벽을 뚫을 수 있음
                if(a[ny][nx]=='1' && b) {
                    visited[ny][nx][b-1]=level;
                    q.push({ny,nx,b-1});
                } else if(a[ny][nx]=='0' && !visited[ny][nx][b]) {
                    visited[ny][nx][b]=level;
                    q.push({ny,nx,b});
                }
            }
        }
        level++;
    }

    return -1;
}

int main() {

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<m;j++) a[i][j]=s.at(j);
    }

    int result=bfs(0,0);
    printf("%d\n",result);

    return 0;
}