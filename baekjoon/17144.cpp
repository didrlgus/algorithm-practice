// 미세먼지 안녕!
#include<bits/stdc++.h>
using namespace std;
int n,m,t,arr[55][55],tmp[55][55],ret;
bool visited[55][55];
vector<pair<int,int>> v,v2;
vector<int> v3;
int dy[]={0,-1,0,1};
int dx[]={1,0,-1,0};

void dfs(int y,int x,int dir) {
    if(arr[y][x]==-1) return;
    if(x==m) {
        dfs(y-1,x-1,dir+1);
        return;
    }
    if(y==-1) {
        dfs(y+1,x-1,dir+1);
        return;
    }
    if(x==-1) {
        dfs(y+1,x+1,dir+1);
        return;
    }
    v2.push_back({y,x});
    v3.push_back({arr[y][x]});
    dfs(y+dy[dir],x+dx[dir],dir);
    return;
}
void dfs2(int y,int x,int dir) {
    if(arr[y][x]==-1) return;
    if(x==m) {
        if(dir-1==-1) dir=4;
        dfs2(y+1,x-1,dir-1);
        return;
    }
    if(y==n) {
        dfs2(y-1,x-1,dir-1);
        return;
    }
    if(x==-1) {
        dfs2(y-1,x+1,dir-1);
        return;
    }
    v2.push_back({y,x});
    v3.push_back({arr[y][x]});
    dfs2(y+dy[dir],x+dx[dir],dir);
    return;
}
int main() {
    scanf("%d %d %d",&n,&m,&t);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==-1) v.push_back({i,j});
        }
    }
    while(t--) {
        fill(&tmp[0][0],&tmp[0][0]+55*55,0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(arr[i][j]>0) {
                    int cnt=0;
                    for(int k=0;k<4;k++) {
                        int ny=i+dy[k],nx=j+dx[k];
                        if(ny<0||nx<0||ny>=n||nx>=m||arr[ny][nx]==-1) continue;
                        tmp[ny][nx]+=arr[i][j]/5;
                        cnt++;
                    }
                    tmp[i][j]+=arr[i][j]-arr[i][j]/5*cnt;
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(tmp[i][j]>0) {
                    arr[i][j]=tmp[i][j];
                }
            }
        }
        int y=v[0].first,x=v[0].second;
        dfs(y,x+1,0);
        rotate(v3.begin(),v3.begin()+v3.size()-1,v3.end());
        v3[0]=0;
        for(int i=0;i<(int)v2.size();i++) arr[v2[i].first][v2[i].second]=v3[i];
        v2.clear();v3.clear();
        y=v[1].first,x=v[1].second;
        dfs2(y,x+1,0);
        rotate(v3.begin(),v3.begin()+v3.size()-1,v3.end());
        v3[0]=0;
        for(int i=0;i<(int)v2.size();i++) arr[v2[i].first][v2[i].second]=v3[i];
        v2.clear();v3.clear();
    }    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) if(arr[i][j]>0) ret+=arr[i][j];
    }
    printf("%d\n",ret);

    return 0;
}