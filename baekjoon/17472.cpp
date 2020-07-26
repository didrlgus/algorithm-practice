// 다리 만들기 2
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[105][105],dy[]={0,0,1,-1},dx[]={1,-1,0,0},num=1,p[10],cnt,ret;
bool visited[105][105];
vector<pair<int,int>> v[10];
struct Edge{
    int u,v,w;
    Edge(){u=-1;v=-1;w=0;}
    Edge(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator<(const Edge & a) const{return w<a.w;}
};
vector<Edge> edg;
void dfs(int y,int x,int num) {
    visited[y][x]=true;
    arr[y][x]=num;
    v[num].push_back({y,x});
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(!visited[ny][nx]&&arr[ny][nx]) dfs(ny,nx,num);
    }
}
void set_bridge(int y,int x,int dir,int from) {
    int dist=1;
    while(true) {
        y=y+dy[dir],x=x+dx[dir];
        if(y<0||x<0||y>=n||x>=m) break;
        if(arr[y][x]) {
            if(dist>=2) edg.push_back({from,arr[y][x],dist});
            break;
        }
        dist++;
    }
}
int uf_find(int a){
    if(p[a]<0) return a; 
    return p[a]=uf_find(p[a]);
}
bool uf_merge(int a,int b){
    a=uf_find(a);
    b=uf_find(b);
    if(a==b) return false;  
    p[b]=a; 
    return true;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!visited[i][j]&&arr[i][j]) dfs(i,j,num++);
        }
    }
    for(int i=1;i<num;i++) {
        for(auto it:v[i]) {
            int y=it.first,x=it.second;
            for(int d=0;d<4;d++) {
                int ny=y+dy[d],nx=x+dx[d];
                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                if(arr[ny][nx]) continue;
                set_bridge(ny,nx,d,i);      // 한방향 탐색
            }
        }
    }
    memset(p,-1,sizeof(p));
    sort(edg.begin(),edg.end());
    for(auto it:edg) {
        if(uf_merge(it.u,it.v)) {
            ret+=it.w;
            if(++cnt==num-2) break;         // num-1이 정점의 개수이므로 num-2만큼의 간선을 고르면 됨
        }
    }
    printf("%d\n",(cnt==num-2)?ret:-1);
    return 0;
}