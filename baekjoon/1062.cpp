// 가르침
#include<bits/stdc++.h>
using namespace std;
const int INF=-987654321;
int n,k,ret=INF;
vector<string> v;
bool visited[30];
int counting() {
    int cnt=0;
    for(string s:v) {
        bool flag=false;
        for(int i=4;i<(int)s.size()-4;i++) {
            if(!visited[s[i]-'a']) {
                flag=true;
                break;
            }
        }
        if(!flag) cnt++;
    }
    return cnt;
}
void combi(int here,int cnt) {
    if(cnt==k) {
        ret=max(ret,counting());
        return;
    }
    for(int i=here+1;i<26;i++) {
        if(visited[i]) continue;
        visited[i]=true;
        combi(i,cnt+1);
        visited[i]=false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        v.push_back(s);
    }
    visited['a'-'a']=true;visited['n'-'a']=true;
    visited['t'-'a']=true;visited['i'-'a']=true;visited['c'-'a']=true;
    k-=5;
    if(k<0) {
        printf("0\n");
        return 0;
    }
    combi(-1,0);
    printf("%d\n",ret);
    return 0;
}