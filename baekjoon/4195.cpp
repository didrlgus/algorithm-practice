// 친구 네트워크
#include<bits/stdc++.h>
using namespace std;
int tc,n,p[100005];
map<string,int> mp;
int uf_find(int a) {
    if(p[a]<0) return a; 
    return p[a]=uf_find(p[a]);
}
int uf_merge(int a,int b) {
    a=uf_find(a);
    b=uf_find(b);
    if(a!=b) {
        p[a]+=p[b];
        p[b]=a;
    }
    return p[a];
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>tc;
    while(tc--) {
        mp.clear();
        memset(p,-1,sizeof(p));
        cin>>n;
        int idx=1;
        for(int i=1;i<=n;i++) {
            string s1,s2;
            cin>>s1>>s2;
            if(!mp[s1]) mp[s1]=idx++;
            if(!mp[s2]) mp[s2]=idx++;
            cout<<abs(uf_merge(mp[s1],mp[s2]))<<'\n';
        }
    }
    return 0;
}