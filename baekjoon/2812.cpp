// 크게 만들기
#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
deque<char> dq;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k>>s;
    for(auto c:s) {
        while(k>0&&!dq.empty()&&dq.back()<c) {
            dq.pop_back();
            k--;
        }
        dq.push_back(c);
    }
    for(int i=0;i<(int)dq.size()-k;i++) cout<<dq[i];
    return 0;
}