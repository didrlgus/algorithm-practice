// 스택수열
#include<bits/stdc++.h>
using namespace std;
int n,num=1;
stack<int> stk;
vector<int> v;
vector<char> ret;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a;scanf("%d",&a);
        v.push_back(a);
    }
    for(auto it:v) {
        while(stk.empty()||(int)stk.top()<it) {
            stk.push(num++);
            ret.push_back('+');
        }
        if(!stk.empty()&&(int)stk.top()==it) {
            stk.pop();
            ret.push_back('-');
        }
    }
    if(stk.empty()) for(auto it:ret) printf("%c\n",it);
    else printf("NO\n");
    return 0;
}