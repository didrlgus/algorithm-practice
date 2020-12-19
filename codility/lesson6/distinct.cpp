#include<bits/stdc++.h>
using namespace std;
int ret;
map<int,bool> mp;
int solution(vector<int> &A) {
    for(auto it:A) {
        if(!mp[it]) {
            ret++;
            mp[it]=true;
        }
    }
    return ret;    
}