#include<bits/stdc++.h>
using namespace std;
int mx,cur_mx;
vector<int> solution(int N, vector<int> &v) {
    vector<int> ret(N,0);
    for(auto it:v) {
        if(it>=N+1) {
            cur_mx=mx;
        } else {
            if(ret[it-1]<cur_mx) ret[it-1]=cur_mx+1;
            else ret[it-1]++;
            mx=max(mx,ret[it-1]);
        }
    }
    for(int i=0;i<(int)ret.size();i++) {
        if(ret[i]<cur_mx) ret[i]=cur_mx;
    }
    return ret;
}