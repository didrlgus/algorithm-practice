// 숫자 카드 2
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v,vv;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a;scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    scanf("%d",&m);
    for(int i=0;i<m;i++) {
        int a;scanf("%d",&a);
        vv.push_back(a);
    }
    for(auto it:vv) printf("%d ",upper_bound(v.begin(),v.end(),it)-lower_bound(v.begin(),v.end(),it));
    return 0;
}