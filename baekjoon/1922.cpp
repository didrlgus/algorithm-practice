// 네트워크 연결
#include<bits/stdc++.h>
using namespace std;
int n,m,p[1005],ret,cnt;
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
struct Edge{
    int u,v,w;
    Edge(){u=-1;v=-1;w=0;}
    Edge(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator<(const Edge & a) const{return w<a.w;}
};
vector<Edge> v;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v.push_back({a,b,c});
    }
    sort(v.begin(),v.end());
    memset(p,-1,sizeof(p));
    int i=0;
    for(auto it:v) {
        if(uf_merge(it.u,it.v)) {
            ret+=it.w;
            if(++cnt==n-1) break;
        }
    }
    printf("%d\n",ret);
    return 0;
}