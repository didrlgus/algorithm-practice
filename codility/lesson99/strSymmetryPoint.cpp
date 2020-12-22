#include<bits/stdc++.h>
using namespace std;
int n,mid;
int solution(string &S) {
    n=(int)S.size();
    if(n==1) return 0;
    if(!(n&1)) return -1;
    mid=n/2;
    for(int i=1;i<=mid;i++) {
        if(S[mid-i]!=S[mid+i]) return -1;
    }
    return mid;
}