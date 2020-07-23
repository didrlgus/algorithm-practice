// 여행 가자
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[205],ret;
bool flag;
set<int> st;
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
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int val;scanf("%d",&val);
            if(val) uf_merge(i,j);
        }
    }
    int a;scanf("%d",&a);
    int root=uf_find(a);
    for(int i=1;i<m;i++) {
        int b;scanf("%d",&b);
        if(root!=uf_find(b)) {
            flag=true;
            break;
        }
    }
    if(!flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}