// 3055. 탈출
#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

int r,c;

char a[55][55];

struct p {
    int y,x;
};

int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

vector<p> wv;
// 고슴도치, 비버의 굴의 좌표
int r1,c1,r2,c2;

queue<p> q1,q2;

bool visited1[55][55];   // 물이 지나가는 경우
bool visited2[55][55];  // 고슴도치가 지나가는 경우

int bfs() {
    // 물의 시작점 큐에 삽입
    for(int i=0;i<wv.size();i++) {
        visited1[wv[i].y][wv[i].x]=true;
        q1.push({wv[i].y,wv[i].x});
    }

    // 고슴도치의 시작점 큐에 삽입
    visited2[r1][c1]=true;
    q2.push({r1,c1});

    int level=0;

    // 물,고슴도치 bfs
    while(!q2.empty()) {
        int size1=q1.size();
        
        while(size1--) {
            int y=q1.front().y;
            int x=q1.front().x;

            q1.pop();

            for(int i=0;i<4;i++) {
                int ny=y+dy[i];
                int nx=x+dx[i];

                if(ny<0 || nx<0 || ny>=r || nx>=c) continue;

                if(!visited1[ny][nx] && a[ny][nx]!='D' && a[ny][nx]!='X') {
                    visited1[ny][nx]=true;
                    q1.push({ny,nx});
                    a[ny][nx]='*';
                }
            }
        }

        int size2=q2.size();

        while(size2--) {
            int y=q2.front().y;
            int x=q2.front().x;

            q2.pop();

            if(y==r2 && x==c2) return level;

            for(int i=0;i<4;i++) {
                int ny=y+dy[i];
                int nx=x+dx[i];

                if(ny<0 || nx<0 || ny>=r || nx>=c) continue;

                if(!visited2[ny][nx] && a[ny][nx]!='*' && a[ny][nx]!='X') {
                    visited2[ny][nx]=true;
                    q2.push({ny,nx});
                }
            }
        }
        level++;
    }
    return -1;
}

int main() {

    cin >> r >> c;

    for(int i=0;i<r;i++) {
        string s;
        cin >> s;
        for(int j=0;j<c;j++) {
            a[i][j]=s.at(j);

            if(a[i][j]=='*') wv.push_back({i,j});
            else if(a[i][j]=='S') r1=i,c1=j;
            else if(a[i][j]=='D') r2=i,c2=j;           
        }
    }

    int result=bfs();

    if(result==-1) {
        printf("KAKTUS");
    } else {
        printf("%d\n",result);
    }

    return 0;
}