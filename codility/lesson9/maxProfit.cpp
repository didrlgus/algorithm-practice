#include<bits/stdc++.h>
using namespace std;
int mn=987654321,ret;
int solution(vector<int> &A) {
    for(auto it:A) {
        mn=min(mn,it);
        ret=max(ret,it-mn);
    }
    return ret;
}