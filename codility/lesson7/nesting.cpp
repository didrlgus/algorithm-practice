#include <bits/stdc++.h>
using namespace std;
stack<char> stk;
int solution(string &S) {
    for(auto it:S) {
        if(it=='(') {
            stk.push(it);
        } else {
            if(stk.empty()) return 0;
            stk.pop();
        }
    }
    if(stk.empty()) return 1;
    return 0;
}