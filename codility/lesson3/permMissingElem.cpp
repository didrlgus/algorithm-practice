#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> &v) {
    int n=(int)v.size();
    if(n==0) return 1;
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++) {
        if(i!=v[i-1]) return i;
    }
    return v.back()+1;
}