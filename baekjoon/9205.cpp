// 맥주 마시면서 걸어가기
#include<bits/stdc++.h>
using namespace std;
int tc,sy,sx,ey,ex;
vector<pair<int,int>> v;
map<pair<int,int>,bool> visited;
bool flag;
void dfs(int y,int x) {
    if(y==ey&&x==ex) flag=true;
    if(flag) return;
    visited[{y,x}]=true;
    for(auto it:v) {
        if(!visited[{it.first,it.second}]) {
            if(abs(y-it.first)+abs(x-it.second)<=1000) dfs(it.first,it.second);
        }
    }
}
int main() {
    scanf("%d",&tc);
    while(tc--) {
        int n;scanf("%d",&n);
        scanf("%d%d",&sy,&sx);
        v.clear();
        visited.clear();
        for(int i=0;i<n;i++) {
            int y,x;
            scanf("%d%d",&y,&x);
            v.push_back({y,x});
        }
        scanf("%d%d",&ey,&ex);
        v.push_back({ey,ex});
        flag=false;
        dfs(sy,sx);
        if(flag) printf("happy\n");
        else printf("sad\n");
    }
    return 0;
}