// 홍준이의 친위대
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tc,n;
ll dp[25][25][3];
ll dfs(int left,int right,bool is_left) {
    int range=left+right;
    if(range==0) return 1;
    ll& ret=dp[left][right][is_left];
    if(ret!=-1) return ret;
    ret=0;
    if(is_left) {
        for(int i=0;i<left;i++) ret+=dfs(i,range-i-1,!is_left);
    } else {
        for(int i=0;i<right;i++) ret+=dfs(range-i-1,i,!is_left);
    }
    return ret;
}
int main() {
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d",&n); 
        if(n==1) {
            printf("1\n");
            continue;
        }
        fill(&dp[0][0][0],&dp[0][0][0]+25*25*3,-1);
        ll ret=0;
        for(int i=0;i<n;i++) {
            ret+=dfs(i,n-i-1,1);
            ret+=dfs(i,n-i-1,0);
        }
        printf("%lld\n",ret);
    }
}