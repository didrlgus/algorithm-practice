// 친구비
#include<bits/stdc++.h>
using namespace std;
int n,m,k,arr[10005],cost[10005],ret;
int uf_find(int a){
    if(arr[a]<0) return a;
    return arr[a]=uf_find(arr[a]);
}
void uf_merge(int a, int b){
    a=uf_find(a);
    b=uf_find(b);
    if(a==b) return;
    if(cost[a]>cost[b]) arr[a]=b;  
    else arr[b]=a; 
    return;
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&cost[i]);
    memset(arr,-1,sizeof(arr));
    for(int i=0;i<m;i++) {
        int a,b;scanf("%d%d",&a,&b);
        uf_merge(a,b);
    }
    for(int i=1;i<=n;i++) {
        if(arr[i]==-1) ret+=cost[i];
    }
    if(ret>k) printf("Oh no\n");
    else printf("%d\n",ret);
    return 0;
}