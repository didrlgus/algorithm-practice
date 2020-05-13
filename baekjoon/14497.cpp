// 주난의 난
#include<bits/stdc++.h>

using namespace std;

int n,m;
char arr[310][310];
bool visited[310][310];
queue<pair<int,int>> q;

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

int main() {
    int y1,x1,y2,x2;    // 주난의 위치 / 범인의 위치
    scanf("%d %d",&n,&m);
    scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
    y1--;x1--;y2--;x2--;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }

    visited[y1][x1];
    q.push({y1,x1});
    
    // 플러드 필 적용(O(n^2) 만에 해결 가능)
    int t=0;
    while(arr[y2][x2]=='#') {
        queue<pair<int,int>> tmp;

        while(!q.empty()) {
            tie(y1,x1)=q.front();
            q.pop();

            for(int i=0;i<4;i++) {
                int ny=y1+dy[i],nx=x1+dx[i];
                
                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                if(!visited[ny][nx] && (arr[ny][nx]=='0' || arr[ny][nx]=='#')) {
                    visited[ny][nx]=true;
                    q.push({ny,nx});
                    if(arr[ny][nx]=='#') arr[ny][nx]='0';
                }
                if(!visited[ny][nx] && arr[ny][nx]=='1') {
                    visited[ny][nx]=true;
                    tmp.push({ny,nx});
                    arr[ny][nx]='0';
                }
            }
        }
        q=tmp;
        t++;
    }

    printf("%d\n",t);

    return 0;
}