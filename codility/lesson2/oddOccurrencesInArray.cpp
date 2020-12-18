#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> &v) {
    sort(v.begin(),v.end());
    for(int i=0;i<(int)v.size();i+=2) {
        if(v[i]!=v[i+1]) return v[i];
    }
    return -1;
}