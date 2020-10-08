// 모양 만들기
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[1005][1005],dy[]={0,0,1,-1},dx[]={1,-1,0,0},val=1,ret=1;
bool visited[1005][1005];
map<int,bool> mp;
vector<int> v;
int check(int y,int x) {
    int cnt=1;
    mp.clear();
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(arr[ny][nx]&&!mp[arr[ny][nx]]) {
            mp[arr[ny][nx]]=true;
            cnt+=v[arr[ny][nx]];
        }
    }
    return cnt;
}
int dfs(int y,int x,int val) {
    visited[y][x]=true;
    arr[y][x]=val;
    int cnt=0;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(!visited[ny][nx]&&arr[ny][nx]) cnt+=dfs(ny,nx,val)+1;
    }
    return cnt;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
    }
    v.push_back(0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!arr[i][j]||visited[i][j]) continue;
            v.push_back(dfs(i,j,val++)+1);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]) continue;
            ret=max(ret,check(i,j));
        }
    }
    printf("%d\n",ret);
    return 0;
}