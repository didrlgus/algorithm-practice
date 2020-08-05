// 숫자고르기
#include<bits/stdc++.h>
using namespace std;
int n;
bool visited[105],check[105];
vector<int> adj[105];
vector<int> ret;
void dfs(int start,int current) {
    if(start==current) {
        ret.push_back(start);
        return;
    }
    if(!visited[current]) {
        visited[current]=true;
        dfs(start,adj[current].front());
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int a;scanf("%d",&a);
        adj[i].push_back(a);
    }
    for(int i=1;i<=n;i++) {
        memset(visited,0,sizeof(visited));
        visited[i]=true;
        dfs(i,adj[i].front());
    }
    printf("%d\n",(int)ret.size());
    for(auto it:ret) printf("%d\n",it);
    return 0;
}