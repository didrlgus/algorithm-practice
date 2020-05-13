// 백조의 호수
#include<bits/stdc++.h>

using namespace std;

int n,m;
char arr[1510][1510];
bool visited[1510][1510];

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

queue<pair<int,int>> q,q2;          // 백조, 물 큐
bool flag=false;

int main() {

    scanf("%d %d",&n,&m);

    int y,x;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf(" %1c",&arr[i][j]);

            if(arr[i][j]=='L') {
                y=i; x=j;                   // 백조의 위치 좌표
                q2.push({i,j});             // 백조도 물로 취급
            } else if(arr[i][j]=='.') {     // 물 미리 채워넣기
                q2.push({i,j});
            }
        }
    }

    int t=0;
    visited[y][x]=true;
    q.push({y,x});
    while(true) {
        // 백조 플러드 필
        queue<pair<int,int>> tmp;
        while(!q.empty()) {
            tie(y,x)=q.front(); q.pop();

            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];
                
                if(ny<0||nx<0||ny>=n||nx>=m || visited[ny][nx]) continue;
                
                if(arr[ny][nx]=='.') {
                    visited[ny][nx]=true;
                    q.push({ny,nx});
                } else if(arr[ny][nx]=='X') {
                    visited[ny][nx]=true;
                    tmp.push({ny,nx});
                } else if(arr[ny][nx]=='L') {
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) break;
        q=tmp;

        // 물 플러드 필
        queue<pair<int,int>> tmp2;
        while(!q2.empty()) {
            int y2,x2;
            tie(y2,x2)=q2.front(); q2.pop();

            for(int i=0;i<4;i++) {
                int ny=y2+dy[i],nx=x2+dx[i];

                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                if(arr[ny][nx]=='X') {
                    tmp2.push({ny,nx});
                    arr[ny][nx]='.';
                }
            }
        }
        q2=tmp2;

        t++;
    }
    
    printf("%d\n",t);

    return 0;
}