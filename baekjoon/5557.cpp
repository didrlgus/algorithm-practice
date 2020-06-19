// 1학년
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,arr[105],dp[105][25];
ll dfs(int here,int val) {
    if(val<0||val>20) return 0;
    if(here==n-2) {
        if(val==arr[n-1]) return 1;
        else return 0;
    }
    ll& ret=dp[here][val];
    if(ret!=-1) return ret;
    ret=0;
    ret+=dfs(here+1,val+arr[here+1]);
    ret+=dfs(here+1,val-arr[here+1]);
    return ret;
}
int main() {
    scanf("%lld",&n);
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    fill(&dp[0][0],&dp[0][0]+105*25,-1);
    printf("%lld\n",dfs(0,arr[0]));   
    return 0;
}