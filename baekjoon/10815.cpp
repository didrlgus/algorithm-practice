// 숫자 카드
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v1,v2;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int val;scanf("%d",&val);
        v1.push_back(val);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++) {
        int val;scanf("%d",&val);
        v2.push_back(val);
    }
    sort(v1.begin(),v1.end());
    for(auto it:v2) {
        int cnt=upper_bound(v1.begin(),v1.end(),it)-lower_bound(v1.begin(),v1.end(),it);
        printf("%d ",cnt?1:0);
    }
    return 0;
}