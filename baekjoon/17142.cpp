// 연구소 3
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,cnt,ret=INF;
int arr[55][55],tmp[55][55];
vector<pair<int,int>> virus;
queue<pair<int,int>> q;
bool visited[55][55];
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
int bfs() {
    int level=1,val=cnt;
    while(!q.empty()) {
        int size=q.size();
        while(size--) {
            int y=q.front().first,x=q.front().second;q.pop();
            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];
                if(ny<0||nx<0||ny>=n||nx>=n) continue;
                if(!visited[ny][nx]&&tmp[ny][nx]==0) {
                    visited[ny][nx]=true;
                    tmp[ny][nx]=level;
                    val--;
                    q.push({ny,nx});
                }
                if(!visited[ny][nx]&&tmp[ny][nx]==2) {
                    visited[ny][nx]=true;
                    tmp[ny][nx]=tmp[y][x];
                    q.push({ny,nx});
                }
            }
        }
        level++;
    }
    if(val==0) {
        int mx=-987654321;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) mx=max(mx,tmp[i][j]);
        }
        return mx;
    }
    else return INF;
}
void combi(int here,vector<int>& v) {
    if((int)v.size()==m) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) tmp[i][j]=arr[i][j];
        }
        fill(&visited[0][0],&visited[0][0]+55*55,false);
        for(auto it:v) {
            int y=virus[it].first,x=virus[it].second;
            visited[y][x]=true;
            tmp[y][x]=0;
            q.push({y,x});
        }
        ret=min(ret,bfs());
        return;
    }
    for(int i=here+1;i<(int)virus.size();i++) {
        v.push_back(i);
        combi(i,v);
        v.pop_back();
    }
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==2) virus.push_back({i,j});
            if(arr[i][j]==1) arr[i][j]=-1;
            if(arr[i][j]==0) cnt++;
        }
    }
    vector<int> v;
    combi(-1,v);
    if(ret==INF) printf("-1\n");
    else printf("%d\n",ret);
    return 0;
}