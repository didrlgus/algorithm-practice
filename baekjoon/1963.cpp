// 소수 경로
#include<bits/stdc++.h>
using namespace std;
int tc,n,m,visited[10000];
bool arr[10000];
vector<int> v;
bool comp(int a,int b) {
    return a==b;
}
bool check(int a,int b) {
    int cnt=0;
    int a1000=a/1000,a100=a%1000/100,a10=a%100/10,a1=a%10;
    int b1000=b/1000,b100=b%1000/100,b10=b%100/10,b1=b%10;
    if(!comp(a1000,b1000)) cnt++;
    if(!comp(a100,b100)) cnt++;
    if(!comp(a10,b10)) cnt++;
    if(!comp(a1,b1)) cnt++;
    if(cnt!=1) return false;
    return true;
}
int bfs(int start) {
    queue<int> q;
    visited[start]=1;
    q.push(start);
    while(!q.empty()) {
        start=q.front();q.pop();
        if(start==m) {
            return visited[start]-1;
        }
        for(auto it:v) {
            if(visited[it]) continue;
            if(check(start,it)) {
                visited[it]=visited[start]+1;
                q.push(it);
            }
        }
    }
    return -1;
}
int main() {
    for(int i=0;i<=9999;i++) arr[i]=true;  
    for(int i=2;i<=9999;i++) {
        if(arr[i]) {
            for(int j=2;j<=9999/i;j++){
                if(arr[i*j]) arr[i*j]=false;
            }
        }
    }
    for(int i=1000;i<=9999;i++) if(arr[i]) v.push_back(i);
    scanf("%d",&tc);
    while(tc--) {
        memset(visited,0,sizeof(visited));
        scanf("%d%d",&n,&m);
        int ret=bfs(n);
        if(ret==-1) printf("Impossible\n");
        else printf("%d\n",ret);
    }
    return 0;
}