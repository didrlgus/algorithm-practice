#include<bits/stdc++.h>
using namespace std;
map<int,bool> mp;
int cnt;
int solution(int x, vector<int> &v) {
    for(int i=0;i<(int)v.size();i++) {
        if(!mp[v[i]]) {
            mp[v[i]]=true;
            cnt++;
        }
        if(cnt>=x) return i;
    }
    return -1;
}