// 좋은수열
#include<bits/stdc++.h>
using namespace std;
int n;
string str="1";
bool flag;
bool check(string str) {
    int len=(int)str.size();
    for(int i=2;i<=len/2;i++) {
        for(int s=0;s<=len-2*i;s++) {
            string a=str.substr(s,i);
            string b=str.substr(s+i,i);
            if(a==b) return false;
        }
    }
    return true;
}
void go(string s) {
    if(flag) return;
    if((int)s.size()==n) {
        cout<<s<<'\n';
        flag=true;
        return;
    }
    for(int i=1;i<=3;i++) {
        if(s.back()-'0'==i) continue;
        if(!check(s+to_string(i))) continue;
        go(s+to_string(i));
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    go(str);
    return 0;
}