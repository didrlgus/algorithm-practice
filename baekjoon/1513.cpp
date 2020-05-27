// 경로 찾기
#include<bits/stdc++.h>
using namespace std;

const int mod=1000007;
int n,m,c;
int arr[55][55],dp[55][55][55][55];
int dfs(int y,int x,int cnt,int prev) {
    if(y>n||x>m) return 0;
    if(y==n&&x==m) {
        if(cnt==0&&arr[y][x]==0) return 1;
        if(cnt==1&&arr[y][x]>prev) return 1;
    }
    if(dp[y][x][cnt][prev]!=-1) return dp[y][x][cnt][prev];
    int& ret=dp[y][x][cnt][prev];
    ret=0;
    if(arr[y][x]==0) {
        ret=(dfs(y,x+1,cnt,prev)+dfs(y+1,x,cnt,prev))%mod;
    }
    if(arr[y][x]>prev) {
        ret=(dfs(y,x+1,cnt-1,arr[y][x])+dfs(y+1,x,cnt-1,arr[y][x]))%mod;
    }
    return ret;
}
int main() {
    scanf("%d %d %d",&n,&m,&c);
    for(int i=1;i<=c;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[a][b]=i;
    }
    fill(&dp[0][0][0][0],&dp[0][0][0][0]+55*55*55*55,-1);
    for(int i=0;i<=c;i++) {
        printf("%d ",dfs(1,1,i,0));
    }
    return 0;
}