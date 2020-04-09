// 9376. 탈옥
#include<cstdio>
#include<string>
#include<string.h>
#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int tc,n,m;

char a[110][110];

struct p {
    int y,x;
};

int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

int visited[105][105][3];
bool check[105][105];

void bfs(int r,int c,int idx) {
    deque<p> dq;
    // 시작정점 큐에 삽입.
    check[r][c]=true;
    visited[r][c][idx]=0;
    dq.push_back({r,c});

    while(!dq.empty()) {
        int y=dq.front().y;
        int x=dq.front().x;
        
        dq.pop_front();

        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];

            if(ny<0 || nx<0 || ny>=n+2 || nx>=m+2) continue;
            
            if(!check[ny][nx]) {
                if(a[ny][nx]=='#') {
                    check[ny][nx]=true;
                    visited[ny][nx][idx]=visited[y][x][idx]+1;
                    dq.push_back({ny,nx});
                } else if(a[ny][nx]=='.') {
                    check[ny][nx]=true;
                    visited[ny][nx][idx]=visited[y][x][idx];
                    dq.push_front({ny,nx});
                }
            }
        }
    }
}

int main() {
    scanf("%d",&tc);

    while(tc--) {
        memset(a, false, sizeof(a));
        scanf("%d %d",&n,&m);

        vector<p> v;
        v.push_back({0,0});     // 상근이의 시작점

        for(int i=0;i<n+2;i++) {
            for(int j=0;j<m+2;j++) {
                if(i==0 || i==n+1 || j==0 || j==m+1) a[i][j]='.';
                else scanf(" %1c",&a[i][j]);

                if(a[i][j]=='$') {
                    a[i][j]='.';
                    v.push_back({i,j});     // 두 죄수의 시작점
                }
            }
        }

        for(int i=0;i<3;i++) {
            bfs(v[i].y,v[i].x,i);
            memset(check,false,sizeof(check));
        }

        int min_=987987987;

        for(int i=0;i<n+2;i++) {
            for(int j=0;j<m+2;j++) {
                if(a[i][j]=='*') continue;
                int sum=visited[i][j][0]+visited[i][j][1]+visited[i][j][2];
                
                if(a[i][j]=='#') sum-=2;
                if(min_>sum) min_=sum;
            }
        }
        
        printf("%d\n",min_);
    }

    return 0;
}