// 인구 이동
#include<bits/stdc++.h>
using namespace std;
int n,l,r,arr[55][55],tmp[55][55],dy[]={0,0,1,-1},dx[]={1,-1,0,0},sum,ret;
bool visited[55][55],flag;
vector<pair<int,int>> v;
void dfs(int y,int x) {
    visited[y][x]=true;
    v.push_back({y,x});
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=n) continue;
        if(!visited[ny][nx]) {
            int diff=abs(arr[y][x]-arr[ny][nx]);
            if(diff>=l&&diff<=r) {
                sum+=arr[ny][nx];
                dfs(ny,nx);
            }
        }
    }
}
int main() {
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
    }
    while(true) {
        v.clear();
        memset(visited,0,sizeof(visited));
        memcpy(tmp,arr,sizeof(arr));
        flag=false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(!visited[i][j]) {
                    sum=0;
                    dfs(i,j);
                    if((int)v.size()>1) {
                        int avg=(sum+arr[i][j])/(int)v.size();
                        flag=true;
                        for(auto it:v) tmp[it.first][it.second]=avg;
                    }
                    v.clear();
                }
            }
        }
        if(!flag) break;
        memcpy(arr,tmp,sizeof(tmp));
        ret++;
    }
    printf("%d\n",ret);
    return 0;
}