// 불!
#include<bits/stdc++.h>

using namespace std;

int n,m;
char arr[1010][1010];

vector<pair<int,int>> f;            // 불의 좌표
int r=-1,c=-1;                      // 지훈이의 좌표 (1개)

queue<pair<int,int>> q1,q2;

bool visited1[1010][1010];
bool visited2[1010][1010];

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

bool flag=false;
int level=0;
bool bfs(int y,int x) {
    visited1[y][x]=true;
    q1.push({y,x});
    
    // 불 시작점 큐에 저장
    for(auto iter:f) {
        visited2[iter.first][iter.second]=true;
        q2.push({iter.first,iter.second});
    }

    while(!q1.empty()) {
        int size1=q1.size();
        while(size1--) {
            tie(y,x)=q1.front();
            q1.pop();

            if(arr[y][x]=='F') continue;    // 이미 불에 탔음
            if(y==0||x==0||y==n-1||x==m-1) return true;   // 가장자리일 경우 탈출 가능

            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];

                if(ny<0||nx<0||ny>=n||nx>=m) continue;

                if(!visited1[ny][nx] && arr[ny][nx]=='.') {
                    visited1[ny][nx]=true;
                    q1.push({ny,nx});
                    arr[ny][nx]='J';
                }
            }
        }
        level++;

        // 불 bfs
        int size2=q2.size();
        while(size2--) {
            int fy=q2.front().first,fx=q2.front().second;
            q2.pop();

            for(int i=0;i<4;i++) {
                int ny=fy+dy[i],nx=fx+dx[i];

                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                if(!visited2[ny][nx] && arr[ny][nx]!='#') {
                    visited2[ny][nx]=true;
                    q2.push({ny,nx});
                    arr[ny][nx]='F';
                }
            }
        }
    }

    return false;
}

int main() {
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf(" %1c",&arr[i][j]);
            if(arr[i][j]=='J') {
                r=i; 
                c=j;
            }                
            if(arr[i][j]=='F') f.push_back({i,j});
        }
    }
    
    if(bfs(r,c)) {
        printf("%d\n",level+1);
    } else printf("IMPOSSIBLE\n");

    return 0;
}