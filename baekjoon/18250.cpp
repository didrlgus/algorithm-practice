// 철도 여행
#include<bits/stdc++.h>
using namespace std;
int n,m,p[200005],in[200005],odd[200005],ret;
vector<pair<int,int>> v;
int uf_find(int a) {
    if(p[a]<0) return a; 
    return p[a]=uf_find(p[a]);
}
void uf_merge(int a,int b) {
    a=uf_find(a);
    b=uf_find(b);
    if(a!=b) {  
        p[b]=a; 
        odd[a]+=odd[b];
    }
}
int main() {
    scanf("%d%d",&n,&m);
    memset(p,-1,sizeof(p));
    for(int i=0;i<m;i++) {
        int a,b;scanf("%d%d",&a,&b);
        v.push_back({a,b});
        in[a]++,in[b]++;
    }
    for(int i=1;i<=n;i++) odd[i]=(in[i]&1);
    for(auto it:v) uf_merge(it.first,it.second);
    for(int i=1;i<=n;i++) {
        if(p[i]>0||!in[i]) continue;
        if(odd[i]) ret+=odd[i]/2;
        else ret++;
    }
    printf("%d\n",ret);
    return 0;
}