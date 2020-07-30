// 숨바꼭질 4
#include<bits/stdc++.h>
using namespace std;
int n,k,dm[]={1,1,2},da[]={1,-1,0},parent[100005],level;
bool visited[100005],flag;
queue<int> q;
void go(int y) {
    if(y==-1) return;
    go(parent[y]);
    printf("%d ",y);
}
int main() {
    scanf("%d%d",&n,&k);
    q.push(n);
    visited[n]=true;
    parent[n]=-1;
    while(!q.empty()) {
        int size=(int)q.size();
        while(size--) {
            int cur=q.front();q.pop();
            if(cur==k) {
                flag=true;
                break;
            }
            for(int i=0;i<3;i++) {
                int next=cur*dm[i]+da[i];
                if(next<0||next>100000) continue;
                if(!visited[next]) {
                    parent[next]=cur;
                    visited[next]=true;
                    q.push(next);
                } 
            }
        }
        if(flag) break;
        level++;
    }
    printf("%d\n",level);
    go(k);
    return 0;
}