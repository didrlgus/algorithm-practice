// 수 묶기
#include<bits/stdc++.h>
using namespace std;
int n,ret;
vector<int> v;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int val;scanf("%d",&val);
        v.push_back(val);
    }
    sort(v.begin(),v.end());
    int l_idx=0,r_idx=n-1;
    while(l_idx<r_idx) {
        if(v[l_idx]<1&&v[l_idx+1]<1) {
            ret+=v[l_idx]*v[l_idx+1];
            l_idx+=2;
        } else break;
    }
    while(r_idx>0) {
        if(v[r_idx]>1&&v[r_idx-1]>1) {
            ret+=v[r_idx]*v[r_idx-1];
            r_idx-=2;
        } else break;
    }
    for(int i=l_idx;i<=r_idx;i++) ret+=v[i];
    printf("%d\n",ret);
    return 0;
}