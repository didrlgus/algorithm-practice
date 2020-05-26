// 주난의 난
#include<bits/stdc++.h>
using namespace std;

int n,m,level;
char arr[310][310];
bool visited[310][310];
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
queue<pair<int,int>> q;
int main() {
    scanf("%d %d",&n,&m);
    int y1,x1,y2,x2;
    scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
    y1--;x1--;y2--;x2--;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }
    visited[y1][x1]=true;
    q.push({y1,x1});
    while(true) {
        queue<pair<int,int>> tmpq;
        while(!q.empty()) {
            int y=q.front().first,x=q.front().second; q.pop();
            if(y==y2&&x==x2) {
                printf("%d\n",level);
                return 0;
            }
            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];
                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                if(!visited[ny][nx]&&arr[ny][nx]!='0') {
                    visited[ny][nx]=true;
                    tmpq.push({ny,nx});
                }
                if(!visited[ny][nx]&&arr[ny][nx]=='0') {
                    visited[ny][nx]=true;
                    q.push({ny,nx});
                }
            }
        }
        level++;
        q=tmpq;
    }
    return 0;
}