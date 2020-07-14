// 스타트 링크
#include<bits/stdc++.h>
using namespace std;
int f,s,g,u,d,visited[1000005];
queue<int> q;
int bfs(int x) {
    visited[x]=1;
    q.push(x);
    while(!q.empty()) {
        x=q.front();q.pop();
        if(x==g) return visited[x];
        int nx=x+u;
        if(nx>=1&&nx<=f) {
            if(!visited[nx]) {
                visited[nx]=visited[x]+1;
                q.push(nx);
            }
        }
        nx=x-d;
        if(nx>=1&&nx<=f) {
            if(!visited[nx]) {
                visited[nx]=visited[x]+1;
                q.push(nx);
            }
        }
    }
    return -1;
}
int main() {
    scanf("%d%d%d%d%d",&f,&s,&g,&u,&d);
    int ret=bfs(s);
    if(ret==-1) printf("use the stairs");
    else printf("%d\n",ret-1);
    return 0;
}