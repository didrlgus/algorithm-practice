// 지그재그 서기
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000;
int n,dp[110][110][2];
// 현재 사람보다 작은사람이 left, 큰사람이 right명 있을 때 
// isLeft(1:더 큰사람을 골라야하는 경우, 0:더 작은 사람을 골라야하는 경우)
int dfs(int left,int right,bool isLeft) {
    int range=left+right;
    if(range==0) return 1;
    int& ret=dp[left][right][isLeft];
    if(ret!=-1) return ret;
    ret=0;
    if(isLeft) {
        for(int i=0;i<left;i++) ret=(ret+dfs(i,range-i-1,0))%mod;
    } else {
        for(int i=0;i<right;i++) ret=(ret+dfs(range-i-1,i,1))%mod;
    }
    return ret;
}
int main() {
    scanf("%d",&n);
    if(n==1) {
        printf("1\n");
        return 0;
    }
    fill(&dp[0][0][0],&dp[0][0][0]+110*110*2,-1);
    int ret=0;
    for(int i=0;i<n;i++) {
        ret=(ret+dfs(i,n-i-1,1))%mod;
        ret=(ret+dfs(i,n-i-1,0))%mod;
    }
    printf("%d\n",ret);
    return 0;
}