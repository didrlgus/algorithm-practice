#include<bits/stdc++.h>
using namespace std;
stack<char> stk;
int solution(string &s) {
    for(auto it:s) {
        if(it=='{'||it=='['||it=='(') stk.push(it);
        else {
            if(stk.empty()) return 0;
            if((it=='}'&&stk.top()=='{')||
                (it==']'&&stk.top()=='[')||
                (it==')'&&stk.top()=='(')) stk.pop();
            else return 0;
        }
    }
    if(stk.empty()) return 1;
    return 0;
}