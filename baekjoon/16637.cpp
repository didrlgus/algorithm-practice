// 괄호 추가하기
#include<bits/stdc++.h>
using namespace std;
const int INF=-987654321;
int n,ret=INF;
string s;
vector<int> num;
vector<char> oper;
int calc(char ch,int a,int b) {
    if(ch=='+') return a+b;
    else if(ch=='-') return a-b;
    return a*b;
}
void go(int here,int val) {
    if(here>=n/2) {
        ret=max(ret,val);
        return;
    }
    go(here+1,calc(oper[here],val,num[here+1]));
    if(here+1<n/2) {
        int next=calc(oper[here+1],num[here+1],num[here+2]);
        go(here+2,calc(oper[here],val,next));
    }
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>s;    
    for(auto c:s) {
        if(c>='0'&&c<='9') num.push_back(c-'0');
        else oper.push_back(c);
    }
    go(0,num[0]);
    cout<<ret<<'\n';
    return 0;
}