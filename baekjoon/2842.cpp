// 집배원 한상덕
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,house_cnt,sy,sx,tired[55][55],lo,hi,ret=INF,dy[]={0,0,1,-1,-1,-1,1,1},dx[]={1,-1,0,0,-1,1,-1,1};
char arr[55][55];
bool visited[55][55];
vector<int> v;
int dfs(int y,int x,int mn,int mx) {
    if(tired[sy][sx]<mn||tired[sy][sx]>mx) return 0;
    visited[y][x]=true;
    int ret=0;
    if(arr[y][x]=='K') ret++;
    for(int i=0;i<8;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=n) continue;
        if(visited[ny][nx]) continue;
        if(tired[ny][nx]<mn||tired[ny][nx]>mx) continue;
        ret+=dfs(ny,nx,mn,mx);
    }
    return ret;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf(" %1c",&arr[i][j]);
            if(arr[i][j]=='K') house_cnt++;
            if(arr[i][j]=='P') sy=i,sx=j;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&tired[i][j]);
            v.push_back(tired[i][j]);
        }
    }
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(v.begin(),v.end());
    while(true) {
        memset(visited,0,sizeof(visited));
        if(dfs(sy,sx,v[lo],v[hi])==house_cnt) {
            ret=min(ret,v[hi]-v[lo]);
            lo++;
        } else if(hi==(int)v.size()) break;
        else hi++;
    }
    printf("%d\n",ret);
    return 0;
}