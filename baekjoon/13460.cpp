// 13460. 구슬 탈출2
#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int n,m;
int ry,rx,by,bx;
int nrx, nry, nbx, nby;

char map[15][15];
bool visited[15][15][15][15];

int dy[]={0,0,-1,1};
int dx[]={-1,1,0,0};

struct p {
    int ry,rx,by,bx;
};

queue<p> q;
int cnt=0;

void bfs() {
    // 시작점 큐에 삽입
    visited[ry][rx][by][bx]=true;
    q.push({ry,rx,by,bx});

    while(!q.empty()) {
        int size=q.size();

        while(size--) {
            int ory=q.front().ry, 
                orx=q.front().rx,
                oby=q.front().by, 
                obx=q.front().bx; 

            if(map[ory][orx]=='O' && map[oby][obx]!='O') {
                printf("%d\n",cnt);
                return;
            }

            q.pop();

            // 빨간공 이동
            for(int i=0;i<4;i++) {
                ry=ory;
                rx=orx;
                bx=obx;
                by=oby;

                while(true) {
                    nry=ry+dy[i],
                    nrx=rx+dx[i];

                    if(map[nry][nrx]=='#' || map[ry][rx]=='O') break;

                    ry=nry;
                    rx=nrx;
                }

                while(true) {
                    nby=by+dy[i],
                    nbx=bx+dx[i];

                    if(map[nby][nbx]=='#' || map[by][bx]=='O') break;

                    by=nby;
                    bx=nbx;
                }
                
                if(ry==by && rx==bx) {
                    // 파란공이 구멍에 들어가면 안됨
                    if(map[by][bx]=='O') continue;
                    if(abs(ry-ory)+abs(rx-orx)>abs(by-oby)+abs(bx-obx)) {
                        ry-=dy[i];
                        rx-=dx[i];
                    } else {
                        by-=dy[i];
                        bx-=dx[i];
                    }
                }

                if(!visited[ry][rx][by][bx]) {
                    visited[ry][rx][by][bx]=true;
                    q.push({ry,rx,by,bx});
                }
            }
        }
        cnt++;

        if(cnt>10) {
            printf("-1\n");
            return;
        }
    }

    // 구멍에 공이 들어가기 전에 먼저 큐가 비는 경우
    printf("-1\n");
}

int main() {

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<m;j++) {
            map[i][j]=s.at(j);

            if(map[i][j]=='R') {            // 빨간공 시작점
                ry=i;
                rx=j;
                map[i][j]='.';
            } else if(map[i][j]=='B') {     // 파란공 시작점
                by=i;
                bx=j;
                map[i][j]='.';
            }
        }
    }
    bfs();
}