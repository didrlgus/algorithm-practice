#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> &H) {
    int ret=0;
    stack<int> stk;
    stk.push(H[0]);
    for(int i=1;i<(int)H.size();i++) {
        int cur_h=H[i];
        while(!stk.empty()&&(int)stk.top()>=cur_h) {
            if((int)stk.top()==cur_h) break;
            stk.pop();
            ret++;
        }
        if(stk.empty()) stk.push(cur_h);
        else if((int)stk.top()!=cur_h) stk.push(cur_h);
    }
    return ret+(int)stk.size();
}