#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> &v) {
    sort(v.begin(),v.end());
    if(v[0]>1) return 0;
    for(int i=0;i<(int)v.size();i++) {
        if(v[i]!=i+1) return 0;
    }
    return 1;
}