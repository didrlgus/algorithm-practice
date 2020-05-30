// 극장 좌석
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ret=1;
ll dp[45];
vector<int> v;
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        int a;
        scanf("%d",&a);
        v.push_back(a);
    }
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
    if((int)v.size()==0) {
        printf("%d\n",dp[n]);
        return 0;
    }
    ret*=dp[v[0]-1];
    for(int i=1;i<(int)v.size();i++) {
        ret*=dp[v[i]-v[i-1]-1];
    }
    ret*=dp[n-v.back()];
    printf("%d\n",ret);
    return 0;
}