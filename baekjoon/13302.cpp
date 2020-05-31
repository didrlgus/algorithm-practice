// 리조트
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,arr[110],dp[110][110];
int dfs(int date,int coupon) {
    if(date>n) return 0;
    int& ret=dp[date][coupon];
    if(ret!=INF) return ret;
    if(arr[date]) return dfs(date+1,coupon);
    ret=min(ret,dfs(date+5,coupon+2)+37000);
    ret=min(ret,dfs(date+3,coupon+1)+25000);
    ret=min(ret,dfs(date+1,coupon)+10000);
    if(coupon>=3) ret=min(ret,dfs(date+1,coupon-3));
    return ret;
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        int a;
        scanf("%d",&a);
        arr[a]=1;
    }
    fill(&dp[0][0],&dp[0][0]+110*110,INF);
    printf("%d\n",dfs(1,0));
    return 0;
}