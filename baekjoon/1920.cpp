// 수 찾기
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
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
        auto it=lower_bound(v.begin(),v.end(),a);
        if(*it==a) printf("1\n");
        else printf("0\n");
    }
    return 0;
}