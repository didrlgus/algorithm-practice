// 아기 상어
#include<bits/stdc++.h>
using namespace std;
int n,arr[25][25],y,x,ret,sharkSize=2,eatSize,dy[]={0,0,1,-1},dx[]={1,-1,0,0};
bool visited[25][25];
int bfs(int yy,int xx) {
    fill(&visited[0][0],&visited[0][0]+25*25,false);
    queue<pair<int,int>> q;
    vector<pair<int,int>> v;
    visited[yy][xx]=true;
    q.push({yy,xx});
    int level=0;
    while(!q.empty()) {
        int size=q.size();
        while(size--) {
            tie(yy,xx)=q.front();q.pop();
            for(int i=0;i<4;i++) {
                int ny=yy+dy[i],nx=xx+dx[i];
                if(ny<0||nx<0||ny>=n||nx>=n) continue;
                if(!visited[ny][nx]&&(arr[ny][nx]==0||arr[ny][nx]==sharkSize)) {
                    visited[ny][nx]=true;
                    q.push({ny,nx});
                }
                if(!visited[ny][nx]&&arr[ny][nx]<sharkSize) {
                    visited[ny][nx]=true;
                    v.push_back({ny,nx});
                }
            }
        }
        level++;
        if((int)v.size()>0) break;
    }
    if((int)v.size()==0) return -1;
    sort(v.begin(),v.end());
    y=v[0].first;x=v[0].second;
    arr[y][x]=0;
    return level;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==9) {
                y=i;x=j;
                arr[i][j]=0;
            }
        }
    }
    while(true) {
        int val=bfs(y,x);
        if(val==-1) break;
        eatSize++;
        if(sharkSize==eatSize) {
            sharkSize++;
            eatSize=0;
        }
        ret+=val;
    }
    printf("%d\n",ret);
    return 0;
}