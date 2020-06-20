// 피보나치 함수
#include<bits/stdc++.h>
using namespace std;
int n,cnt0,cnt1,dp[45];
int dfs(int x) {
    if(x==0) return 0;
    else if(x==1) return 1;
    int& ret=dp[x];
    if(ret) return ret;
    ret=dfs(x-1)+dfs(x-2);
    return ret;
}
int main() {
    scanf("%d",&n);
    dp[0]=0;dp[1]=1;
    while(n--) {
        int a;
        scanf("%d",&a);
        if(a==0) {
            printf("1 0\n");
            continue;
        } else if(a==1) {
            printf("0 1\n");
            continue;
        }
        dfs(a);
        printf("%d %d\n",dp[a-1],dp[a]);
    }
    return 0;
}