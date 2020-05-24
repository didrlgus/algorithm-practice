// 안녕
#include<bits/stdc++.h>

using namespace std;

int n,L[110],J[110];
vector<int> dp1,dp2;
int main() {

    scanf("%d",&n);
    dp1.resize(100);
    dp2.resize(100);
    for(int i=1;i<=n;i++) {
        scanf("%d",&L[i]);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&J[i]);
    }

    for(int i=1;i<=n;i++) {
        fill(dp2.begin(),dp2.end(),0);
        for(int j=1;j<=99;j++) {
            if(j>=L[i]) dp2[j]=max(dp1[j],dp1[j-L[i]]+J[i]);
            else dp2[j]=dp1[j];
        }
        dp1=dp2;
    }
    printf("%d\n",dp1[99]);

    return 0;
}