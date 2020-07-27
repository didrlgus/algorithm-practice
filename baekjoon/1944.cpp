// 복제 로봇
#include<bits/stdc++.h>
using namespace std;
int n,m,dy[]={0,0,1,-1},dx[]={1,-1,0,0},visited[55][55],node_num[55][55],val,cnt,ret,p[255];
char arr[55][55];
vector<pair<int,int>> v;
struct Edge {
    int u,v,w;
    Edge(){u=-1;v=-1;w=0;}
    Edge(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator<(const Edge & a) const{return w<a.w;}
};
vector<Edge> edg;
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
bool bfs(int y,int x,int from) {
    queue<pair<int,int>> q;
    fill(&visited[0][0],&visited[0][0]+55*55,0);
    visited[y][x]=1;
    q.push({y,x});
    int node_cnt=0;
    while(!q.empty()) {
        tie(y,x)=q.front();q.pop();
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=n||arr[ny][nx]=='1') continue;
            if(!visited[ny][nx]) {
                visited[ny][nx]=visited[y][x]+1;
                q.push({ny,nx});
                if(arr[ny][nx]=='S'||arr[ny][nx]=='K') {
                    edg.push_back({from,node_num[ny][nx],visited[ny][nx]-1});
                    node_cnt++;
                }
            }
        }
    }
    return m==node_cnt;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf(" %1c",&arr[i][j]);
            if(arr[i][j]=='S'||arr[i][j]=='K') {
                v.push_back({i,j});
                node_num[i][j]=val++;
            }
        }
    }
    for(int i=0;i<m+1;i++) {
        if(!bfs(v[i].first,v[i].second,i)) {
            printf("-1\n");
            return 0;
        }
    }
    sort(edg.begin(),edg.end());
    memset(p,-1,sizeof(p));
    for(auto it:edg) {
        if(uf_merge(it.u,it.v)) {
            ret+=it.w;
            if(++cnt==val-1) break;
        }
    }
    printf("%d\n",ret);
    return 0;
}