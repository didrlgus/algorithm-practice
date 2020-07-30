// 불
#include<bits/stdc++.h>
using namespace std;
int tc,n,m,dy[]={0,0,1,-1},dx[]={1,-1,0,0},y,x;
char arr[1005][1005];
int visited1[1005][1005],visited2[1005][1005];
int main() {
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d%d",&m,&n);
        fill(&arr[0][0],&arr[0][0]+1005*1005,'0');
        memset(visited1,0,sizeof(visited1));
        memset(visited2,0,sizeof(visited2));
        queue<pair<int,int>> q,fire_q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                scanf(" %1c",&arr[i][j]);
                if(arr[i][j]=='@') {
                    visited1[i][j]=1;
                    q.push({i,j}); 
                }
                if(arr[i][j]=='*') {
                    visited2[i][j]=1;
                    fire_q.push({i,j});
                }
            }
        }
        int ret=-1;
        while(!q.empty()&&ret==-1) {
            int fire_q_size=(int)fire_q.size();
            while(fire_q_size--) {
                tie(y,x)=fire_q.front();fire_q.pop();
                for(int i=0;i<4;i++) {
                    int ny=y+dy[i],nx=x+dx[i];
                    if(ny<0||nx<0|ny>=n||nx>=m) continue;
                    if(!visited2[ny][nx]&&arr[ny][nx]!='#') {
                        visited2[ny][nx]=visited2[y][x]+1;
                        fire_q.push({ny,nx});
                        arr[ny][nx]='*';
                    }
                }
            }
            int q_size=(int)q.size();
            while(q_size--) {
                tie(y,x)=q.front();q.pop();
                if(y==0||x==0||y==n-1||x==m-1) {
                    ret=visited1[y][x];
                    break;
                }
                for(int i=0;i<4;i++) {
                    int ny=y+dy[i],nx=x+dx[i];
                    if(ny<0||nx<0|ny>=n||nx>=m) continue;
                    if(!visited1[ny][nx]&&arr[ny][nx]=='.') {
                        visited1[ny][nx]=visited1[y][x]+1;
                        q.push({ny,nx});
                        arr[ny][nx]='@';
                    }
                }
            }
        }
        if(ret==-1) printf("IMPOSSIBLE\n");
        else printf("%d\n",ret);
    }
    return 0;
}