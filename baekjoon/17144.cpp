// 미세먼지 안녕!
#include<bits/stdc++.h>
using namespace std;
int n,m,t,arr[55][55],tmp[55][55],dy[]={0,0,1,-1},dx[]={1,-1,0,0},hy,hx,ly,lx,ret;
vector<int> cleaner;
vector<pair<int,int>> v1,v2;
void spread() {
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]>0) {
                int val=arr[i][j];
                for(int d=0;d<4;d++) {
                    int ny=i+dy[d],nx=j+dx[d];
                    if(ny<0||nx<0||ny>=n||nx>=m) continue;
                    if(arr[ny][nx]==-1) continue;
                    tmp[ny][nx]+=val/5;
                    arr[i][j]-=val/5;
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) arr[i][j]+=tmp[i][j];
    }
}
void dfs(int y,int x,int dir) {
    if(y==hy&&x==hx) return;
    if(x==m-1) dir=3; 
    if(y==0) dir=1;
    if(x==0) dir=2;
    v1.push_back({y,x});
    dfs(y+dy[dir],x+dx[dir],dir);
}
void dfs2(int y,int x,int dir) {
    if(y==ly&&x==lx) return;
    if(x==m-1) dir=2;
    if(y==n-1) dir=1;
    if(x==0) dir=3;
    v2.push_back({y,x});
    dfs2(y+dy[dir],x+dx[dir],dir);
}
void go() {
    vector<int> vv1,vv2;
    for(auto it:v1) vv1.push_back(arr[it.first][it.second]);
    for(auto it:v2) vv2.push_back(arr[it.first][it.second]);
    rotate(vv1.begin(),vv1.begin()+vv1.size()-1,vv1.end()); 
    rotate(vv2.begin(),vv2.begin()+vv2.size()-1,vv2.end());
    vv1[0]=0;vv2[0]=0;
    for(int i=0;i<(int)v1.size();i++) arr[v1[i].first][v1[i].second]=vv1[i];
    for(int i=0;i<(int)v2.size();i++) arr[v2[i].first][v2[i].second]=vv2[i];
}
int main() {
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==-1) cleaner.push_back(i*100+j);
        }
    }
    hy=cleaner.front()/100,hx=cleaner.front()%100;
    ly=cleaner.back()/100,lx=cleaner.back()%100;
    dfs(hy,hx+1,0);
    dfs2(ly,lx+1,0);
    while(t--) {
        spread();
        go();
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) if(arr[i][j]>0) ret+=arr[i][j];
    }
    printf("%d\n",ret);
    return 0;
}