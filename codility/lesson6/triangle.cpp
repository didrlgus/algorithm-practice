#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int solution(vector<int> &A) {
    sort(A.begin(),A.end());
    n=(int)A.size();
    for(int i=n-1;i>=2;i--) {
        ll R=(ll)A[i];
        ll Q=(ll)A[i-1],P=(ll)A[i-2];
        if(R<P+Q) return 1;
    }
    return 0;
}