// 아맞다우산
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,s,e,dy[]={0,0,1,-1},dx[]={1,-1,0,0},visited[55][55],ey,ex,ret=INF;
char arr[55][55];
vector<int> v;
int bfs(int y,int x) {
    memset(visited,0,sizeof(visited));  
    queue<pair<int,int>> q;
    visited[y][x]=1;
    q.push({y,x});
    while(!q.empty()) {
        tie(y,x)=q.front();q.pop();
        if(y==ey&&x==ex) break;
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(!visited[ny][nx]&&arr[ny][nx]!='#') {
                visited[ny][nx]=visited[y][x]+1;
                q.push({ny,nx});
            }   
        }   
    }
    return visited[ey][ex]-1;
}
int main() {
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf(" %1c",&arr[i][j]);
            if(arr[i][j]=='S') s=i*100+j;
            if(arr[i][j]=='X') v.push_back(i*100+j);
            if(arr[i][j]=='E') e=i*100+j;
        }
    }
    if(!(int)v.size()) {
        ey=e/100,ex=e%100;
        printf("%d\n",bfs(s/100,s%100));
        return 0;
    }
    do {
        int dist=0;
        ey=v.front()/100,ex=v.front()%100;
        dist+=bfs(s/100,s%100);
        for(int i=0;i<(int)v.size()-1;i++) {
            ey=v[i+1]/100,ex=v[i+1]%100;
            dist+=bfs(v[i]/100,v[i]%100);
        }
        ey=e/100,ex=e%100;
        dist+=bfs(v.back()/100,v.back()%100);
        ret=min(ret,dist);
    } while(next_permutation(v.begin(),v.end()));
    printf("%d\n",ret);
    return 0;
}