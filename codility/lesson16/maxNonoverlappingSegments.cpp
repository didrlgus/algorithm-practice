#include<bits/stdc++.h>
using namespace std;
int n,ret;
int solution(vector<int> &A, vector<int> &B) {
    n=(int)A.size();
    if(n==0) return 0;
    ret++;
    int end=B[0];
    for(int i=1;i<n;i++) {
        int cur_start=A[i],cur_end=B[i];
        if(end<cur_start) {
            end=cur_end;
            ret++;
        }
    }
    return ret;
}