// 전력난
#include<bits/stdc++.h>
using namespace std;
int n,m,p[200005],a,b,c;
int uf_find(int a){
    if(p[a]<0) return a; 
    return p[a]=uf_find(p[a]);
}
bool uf_merge(int a,int b){
    a=uf_find(a);
    b=uf_find(b);
    if(a==b) return false;  
    p[b]=a; 
    return true;
}
struct Edge {
    int u,v,w;
    Edge(){u=-1;v=-1;w=0;}
    Edge(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator<(const Edge & a) const{return w<a.w;}
};
vector<Edge> edg;
int main() {
    while(true) {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0) break;
        int sum=0;
        edg.clear();
        for(int i=0;i<m;i++) {
            scanf("%d%d%d",&a,&b,&c);
            edg.push_back({a,b,c});
            sum+=c;
        }
        memset(p,-1,sizeof(p));
        sort(edg.begin(),edg.end());
        int ret=0,cnt=0;
        for(auto it:edg) {
            if(uf_merge(it.u,it.v)) {
                ret+=it.w;
                if(++cnt==n-1) break;
            }
        }
        printf("%d\n",sum-ret);
    }
    return 0;
}