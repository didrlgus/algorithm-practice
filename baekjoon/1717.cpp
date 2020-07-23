// 집합의 표현
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[1000005];
int uf_find(int a){
    if(arr[a]<0) return a; 
    return arr[a]=uf_find(arr[a]);
}
void uf_merge(int a, int b){
    a=uf_find(a);
    b=uf_find(b);
    if(a==b) return;  
    arr[b]=a; 
    return;
}
int main() {
    scanf("%d%d",&n,&m);
    memset(arr,-1,sizeof(arr));
    for(int i=0;i<m;i++) {
        int t,a,b;
        scanf("%d%d%d",&t,&a,&b);
        if(t==0) {
            uf_merge(a,b);
        } else {
            bool ret=uf_find(a)==uf_find(b);
            if(ret) printf("YES\n");
            else printf("NO\n"); 
        }
    }
    return 0;
}