// 연속합
#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> v,dp;
int main() {

    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        v.push_back(a);
    }

    dp.push_back(v[0]);

    for(int i=1;i<n;i++) {
        dp.push_back(max(dp[i-1],0)+v[i]);
    }

    sort(dp.begin(),dp.end());
    printf("%d\n",dp.back());

    return 0;
}