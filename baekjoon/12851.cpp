// 숨바꼭질 2
#include<bits/stdc++.h>
using namespace std;
int n,k,dm[]={1,1,2},da[]={1,-1,0},ret;
bool visited[100005];
queue<int> q;
int main() {
    scanf("%d%d",&n,&k);
    q.push(n);
    visited[n]=true;
    int level=0;
    while(!q.empty()) {
        int size=(int)q.size();
        while(size--) {
            int cur=q.front();q.pop();
            visited[cur]=true;
            if(cur==k) ret++;
            for(int i=0;i<3;i++) {
                int next=cur*dm[i]+da[i];
                if(next<0||next>100000) continue;
                if(!visited[next]) q.push(next);
            }
        }
        if(ret) break;
        level++;
    }
    printf("%d\n%d\n",level,ret);
    return 0;
}