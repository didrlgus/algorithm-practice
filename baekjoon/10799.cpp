// 쇠막대기
#include<bits/stdc++.h>
using namespace std;
string s;
stack<char> stk;
int ret;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>s;
    for(int i=0;i<(int)s.size();i++) {
        if(s[i]=='(') stk.push(s[i]);
        else {
            if(s[i-1]=='(') {
                stk.pop();
                ret+=(int)stk.size();
            } else {
                stk.pop();
                ret++;
            }
        }
    }
    printf("%d\n",ret);
    return 0;
}