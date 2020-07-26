// 도시 분할 계획
#include<bits/stdc++.h>
using namespace std;
int n,m,p[100005],cnt,ret;
struct Edge {
    int u,v,w;
    Edge(){u=-1;v=-1;w=0;}
    Edge(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator<(const Edge & a) const{return w<a.w;}
};
vector<Edge> edg;
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
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        edg.push_back({a,b,c});
    }
    memset(p,-1,sizeof(p));
    sort(edg.begin(),edg.end());
    for(auto it:edg) {
        if(uf_merge(it.u,it.v)) {
            ret+=it.w;
            if(++cnt==n-2) break;           // 두개의 마을로 분할하므로 n-2개의 간선 선택
        }
    }
    printf("%d\n",ret);
    return 0;
}