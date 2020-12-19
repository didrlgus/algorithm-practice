#include<bits/stdc++.h>
using namespace std;
vector<int> east,west;
int ret;
int solution(vector<int> &v) {
    for(int i=0;i<(int)v.size();i++) {
        if(v[i]==0) east.push_back(i);
        else west.push_back(i);
    }
    for(int i=0;i<(int)east.size();i++) {
        int val=east[i];
        ret+=west.end()-upper_bound(west.begin(),west.end(),val);
        if(ret>1000000000) return -1;
    }
    return ret;
}