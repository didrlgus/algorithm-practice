// 가르침
#include<bits/stdc++.h>
using namespace std;
int n,k,words[55];
int go(int here,int cnt,int teach) {
    if(cnt==k) {
        int cnt=0;
        for(int i=0;i<n;i++) if(!(words[i]&~teach)) cnt++;
        return cnt;
    }
    int ret=-1;
    for(int i=here+1;i<26;i++) {
        if(i==('a'-'a')||i==('n'-'a')||i==('t'-'a')||i==('i'-'a')||i==('c'-'a')) continue;
        ret=max(ret,go(i,cnt+1,teach|(1<<i)));
    }
    return ret;
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        for(auto c:s) words[i]|=(1<<(c-'a'));
    }
    if(k<5) {
        cout<<0<<'\n';
        return 0;
    }
    k-=5;
    int teach=(1<<'a'-'a')|(1<<'n'-'a')|(1<<'t'-'a')|(1<<'i'-'a')|(1<<'c'-'a');
    cout<<go(-1,0,teach)<<'\n';
    return 0;
}