#include<bits/stdc++.h>
using namespace std;
int n,ret=-2147483648;
vector<int> v;
int solution(vector<int> &A) {
    n=(int)A.size();
    v.push_back(A[0]);
    for(int i=1;i<n;i++) {
        v.push_back(max(v[i-1],0)+A[i]);
    }
    for(auto it:v) ret=max(ret,it);
    return ret;
}