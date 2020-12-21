#include<bits/stdc++.h>
using namespace std;
int n,wall,depth[100005],ret;
int solution(vector<int> &A) {
    n=(int)A.size();
    wall=A[0];
    for(int i=1;i<n-1;i++) {
        if(wall<A[i]) wall=A[i];
        else depth[i]=wall-A[i];
    }
    wall=A[n-1];
    for(int i=n-2;i>=1;i--) {
        if(wall<A[i]) {
            wall=A[i];
        } else {
            ret=max(ret,min(depth[i],wall-A[i]));
        }
    }
    return ret;
}