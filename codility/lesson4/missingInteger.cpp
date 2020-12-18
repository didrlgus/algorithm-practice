#include<bits/stdc++.h>
using namespace std;
int cur_val;
int solution(vector<int> &v) {
    sort(v.begin(),v.end());
    if(v.back()<0||v.front()>1) return 1;
    int idx=-1;
    for(int i=0;i<(int)v.size();i++) {
        if(v[i]>=0) {
            cur_val=v[i];
            idx=i+1;
            break;
        }
    }
    if(cur_val>1) return 1;
    for(int i=idx;i<(int)v.size();i++) {
        if(v[i]-1!=cur_val&&v[i]!=cur_val) return cur_val+1;
        cur_val=v[i];
    }
    return v.back()+1;
}