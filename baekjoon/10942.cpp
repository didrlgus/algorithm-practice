// 팰린드롬?
#include<bits/stdc++.h>
using namespace std;
// dp[i][j] -> i에서j까지의 수가 팰린드롬이면 1, 아니면 0 저장
int n,m,s,e,arr[2010],dp[2010][2010];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++) dp[i][i]=1;
    for(int size_=2;size_<=n;size_++) {
        for(int i=0;i<=n-size_;i++) {
            int j=i+size_-1;
            if(arr[i]==arr[j]&&(i+1==j||dp[i+1][j-1])) dp[i][j]=1;
        }
    }
    scanf("%d",&m);
    while(m--) {
        scanf("%d %d",&s,&e);
        printf("%d\n",dp[s-1][e-1]);
    }
    return 0;
}