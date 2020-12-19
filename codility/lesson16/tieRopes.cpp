#include<bits/stdc++.h>
using namespace std;
int n,sum,ret;
int solution(int K, vector<int> &A) {
    n=(int)A.size();
    int idx=0;
    while(idx<n) {
        sum+=A[idx++];
        if(sum>=K) {
            sum=0;
            ret++;
        }
    }
    return ret;
}