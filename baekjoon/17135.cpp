// 캐슬 디펜스
#include<bits/stdc++.h>
using namespace std;
int n,m,k,arr[20][20],tmp[20][20],dy[]={0,0,1,-1},dx[]={1,-1,0,0},ans;
vector<pair<int,int>> v,archer,enemy,ret;
vector<int> v2;
bool visited[20][20];
bool cmp(pair<int,int> p1,pair<int,int> p2) {
    if(p1.second==p2.second) return p1.first>p2.first;
    return p1.second<p2.second;
}
void bfs(int y,int x) {
    memset(visited,false,sizeof(visited));
    queue<pair<int,int>> q;
    visited[y][x]=true;
    q.push({y,x});
    int level=0;
    bool flag=false;
    while(!q.empty()) {
        int size=(int)q.size();
        if(level>=k) break;
        while(size--) {
            tie(y,x)=q.front();q.pop();
            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];
                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                if(!visited[ny][nx]) {
                    if(arr[ny][nx]==1) flag=true;
                    visited[ny][nx]=true;
                    q.push({ny,nx});
                }
            }
        }
        if(flag) break;
        level++;
    }
    vector<pair<int,int>> vv;
    while(!q.empty()&&flag) {
        int row=q.front().first,col=q.front().second;q.pop();
        if(arr[row][col]) vv.push_back({row,col});
    }
    sort(vv.begin(),vv.end(),cmp);
    if(vv.size()>0) ret.push_back({vv[0].first,vv[0].second});
}
void combi(int here) {
    if((int)v2.size()>=3) {
        memcpy(arr,tmp,sizeof(tmp));
        archer.clear();
        for(auto it:v2) archer.push_back({v[it].first,v[it].second});
        int cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) if(arr[i][j]) cnt++;
        }
        int dead=0;
        while(cnt) {
            ret.clear();enemy.clear();
            for(auto it:archer) bfs(it.first,it.second);
            for(auto it:ret) {
                if(arr[it.first][it.second]) {
                    arr[it.first][it.second]=0;
                    dead++;
                    cnt--;
                }
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    if(arr[i][j]) {
                        arr[i][j]=0;
                        enemy.push_back({i,j});
                    }
                }
            }
            for(auto it:enemy) {
                int ny=it.first+1,nx=it.second;
                if(ny>=n) {
                    cnt--;
                    continue;
                }
                arr[ny][nx]=1;
            }
        }
        ans=max(ans,dead);
        return;
    }
    for(int i=here+1;i<(int)v.size();i++) {
        v2.push_back(i);
        combi(i);
        v2.pop_back();
    }
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
    }
    for(int j=0;j<m;j++) v.push_back({n,j});
    memcpy(tmp,arr,sizeof(arr));
    combi(-1);
    printf("%d\n",ans);
    return 0;
}