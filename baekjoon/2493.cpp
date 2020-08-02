// 탑
#include<bits/stdc++.h>
using namespace std;
int n,a;
stack<int> stk,stk_idx;
vector<int> ret;
int main() {
    scanf("%d%d",&n,&a);
    stk.push(a);ret.push_back(0);
    stk_idx.push(1);
    for(int i=2;i<=n;i++) {
        scanf("%d",&a);
        while(!stk.empty()) {
            if(a<stk.top()) {
                ret.push_back(stk_idx.top());
                break;
            }
            stk.pop();
            stk_idx.pop();
        }
        if(stk.empty()) ret.push_back(0);
        stk.push(a);
        stk_idx.push(i);
    }
    for(auto it:ret) printf("%d ",it);
    return 0;
}