// 제로
#include<bits/stdc++.h>
using namespace std;
int n,ret;
stack<int> stk;
int main() {
    scanf("%d",&n);
    while(n--) {
        int a;scanf("%d",&a);
        if(a==0) stk.pop();
        else stk.push(a);
    }
    while(!stk.empty()) {
        ret+=stk.top();
        stk.pop();
    }
    printf("%d\n",ret);
    return 0;
}