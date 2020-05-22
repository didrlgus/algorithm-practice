// 동전 2
#include<bits/stdc++.h>

using namespace std;

int n,k;
int arr[110];
int dp[110][10010];
int const INF=987654321;
// N번째 동전까지 선택했을 때 K를 만들 수 있는 최소 경우의 수를 반환하는 함수
int dfs(int N,int K) {
    if(N==n) return (K==0)?0:INF;
    if(dp[N][K]!=-1) return dp[N][K];

    int& ret=dp[N][K];
    int mn=dfs(N+1,K);                                  // N번째 동전을 사용하지 않는 경우
    if(K>=arr[N]) mn=min(mn,dfs(N,K-arr[N])+1);         // N번째 동전을 사용하는 경우
    ret=mn;
    return ret;
}

int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    fill(&dp[0][0],&dp[0][0]+110*10010,-1);
    int result=dfs(0,k);
    if(result==INF) printf("-1\n");
    else printf("%d",result);
    return 0;
}