#include<bits/stdc++.h>
using namespace std;
int n,ret;
int solution(vector<int> &A) {
    n=(int)A.size();
    sort(A.begin(),A.end());
    if(A[0]<0&&A[1]<0) {
        ret=max(A[0]*A[1]*A[n-1],A[n-3]*A[n-2]*A[n-1]);
    } else {
        ret=A[n-3]*A[n-2]*A[n-1];
    }
    return ret;
}