// 불!
#include<bits/stdc++.h>

using namespace std;

int n,m,level;
char arr[1010][1010];
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
queue<pair<int,int>> q1,q2;
bool visited1[1010][1010],visited2[1010][1010];

int bfs() {
    while(!q1.empty()) {
        int size=(int)q1.size();
        while(size--) {
            int y=q1.front().first,x=q1.front().second;
            q1.pop();

            if(arr[y][x]=='F') continue;
            if(y==0||x==0||y==n-1||x==m-1) return level;

            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];

                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                if(!visited1[ny][nx]&&arr[ny][nx]=='.') {
                    visited1[ny][nx]=true;
                    q1.push({ny,nx});
                }
            } 
        }
        int size2=(int)q2.size();
        while(size2--) {
            int y=q2.front().first,x=q2.front().second;
            q2.pop();

            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];

                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                if(!visited2[ny][nx]&&arr[ny][nx]!='#') {
                    visited2[ny][nx]=true;
                    arr[ny][nx]='F';
                    q2.push({ny,nx});
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
        for(int j=0;j<m;j++) {
            scanf(" %1c",&arr[i][j]);
            if(arr[i][j]=='J') {
                q1.push({i,j});
                visited1[i][j]=true;
            }
            else if(arr[i][j]=='F') {
                q2.push({i,j});
                visited2[i][j]=true;
            }
        }
    }
    int ret=bfs();
    if(ret==-1) printf("IMPOSSIBLE\n");
    else printf("%d\n",ret+1);

    return 0;
}