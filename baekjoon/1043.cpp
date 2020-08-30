// 거짓말
#include<bits/stdc++.h>
using namespace std;
int n,m,k,ret,p[55];
vector<int> v;
vector<vector<int>> vv(55);
int uf_find(int a) {
    if(p[a]<0) return a; 
    return p[a]=uf_find(p[a]);
}
bool uf_merge(int a,int b) {
    a=uf_find(a);
    b=uf_find(b);
    if(a==b) return false;  
    p[b]=a; 
    return true;
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++) {
        int a;scanf("%d",&a);
        v.push_back(a);
    }
    memset(p,-1,sizeof(p));
    for(int i=0;i<m;i++) {
        int a,prev;scanf("%d",&a);
        for(int j=0;j<a;j++) {
            int b;scanf("%d",&b);
            if(j>0) uf_merge(prev,b);
            prev=b;
            vv[i].push_back(b);
        }
    }
    for(auto party:vv) {
        if((int)party.size()==0) break;
        bool flag=false;
        for(auto person:party) {
            for(auto know:v) {
                if(uf_find(know)==uf_find(person)) {
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) ret++;
    }
    printf("%d\n",ret);
    return 0;
}