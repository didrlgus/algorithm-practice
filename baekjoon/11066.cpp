// 파일 합치기
#include<bits/stdc++.h>
using namespace std; 
const int INF=987654321;
int tc,n,arr[505],dp[505][505];
int go(int s,int e){
    if(s==e) return dp[s][e] = 0;
    int& ret=dp[s][e]; 
    if(ret!=-1) return ret;
    int sum=0; 
    for(int i=s;i<=e;i++) sum+=arr[i];
    ret=INF;
    for(int i=s;i<=e-1;i++){ 
        ret=min(ret,go(s,i)+go(i+1,e)+sum);
    }
    return ret;
}
int main(){
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d",&n);
        memset(arr,-1,sizeof(arr));
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
        printf("%d\n",go(1,n));
    }
    return 0;
}