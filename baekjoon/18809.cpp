// Gaaaaaaaaaarden
#include<bits/stdc++.h>
using namespace std;
const int FLOWER=5;
struct p {
    int y,x,color;
};
int n,m,g,r,arr[55][55],tmp[55][55],dy[]={0,0,1,-1},dx[]={1,-1,0,0},ret,visited[55][55];
vector<pair<int,int>> candi;
vector<int> v;
queue<p> q;
int bfs() {
    int f_cnt=0;
    while(!q.empty()) {
        int y=q.front().y,x=q.front().x,color=q.front().color;q.pop();
        if(tmp[y][x]==FLOWER) continue;
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(tmp[ny][nx]==0||tmp[ny][nx]==FLOWER||tmp[ny][nx]==color) continue;
            if(!visited[ny][nx]&&(tmp[ny][nx]==1||tmp[ny][nx]==2)) {
                visited[ny][nx]=visited[y][x]+1;
                tmp[ny][nx]=color;
                q.push({ny,nx,color});
            } else {
                if(visited[ny][nx]!=visited[y][x]+1) continue;
                tmp[ny][nx]=FLOWER;
                f_cnt++;
            }
        }
    }
    return f_cnt;
}
void func() {
    for(int i=0;i<g;i++) v.push_back(3);
    for(int i=0;i<r;i++) v.push_back(4);
    for(int i=0;i<(int)candi.size()-g-r;i++) v.push_back(0);
    sort(v.begin(),v.end());
    do {
        memcpy(tmp,arr,sizeof(arr));
        memset(visited,0,sizeof(visited));
        for(int i=0;i<(int)candi.size();i++) {
            int y=candi[i].first,x=candi[i].second;
            if(v[i]==3) {
                visited[y][x]=1;
                tmp[y][x]=3;
                q.push({y,x,3});
            } else if(v[i]==4) {
                visited[y][x]=1;
                tmp[y][x]=4;
                q.push({y,x,4});
            }
        }
        ret=max(ret,bfs());
     } while(next_permutation(v.begin(),v.end()));
}
int main() {
    scanf("%d%d%d%d",&n,&m,&g,&r);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==2) candi.push_back({i,j});
        }
    }
    func();
    printf("%d\n",ret);
    return 0;
}