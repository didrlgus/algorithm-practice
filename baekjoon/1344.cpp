// 축구
#include<bits/stdc++.h>
using namespace std;
const int n=18;
double a,b,dp[20][20][20];
bool isPrime(int x) {
  if(x==0||x==1) return false;
  for(int i=2;i<=sqrt(x);i++) {
    if(x%i==0) return false;
  }
  return true;
}
double dfs(int idx,int ag,int bg) {
    if(idx==n) return isPrime(ag)||isPrime(bg)?1.0:0.0;
    double& ret=dp[idx][ag][bg];
    if(ret>-1) return ret;
    ret=0.0;
    ret+=dfs(idx+1,ag+1,bg)*a*(1-b);
    ret+=dfs(idx+1,ag+1,bg+1)*a*b;
    ret+=dfs(idx+1,ag,bg+1)*(1-a)*b;
    ret+=dfs(idx+1,ag,bg)*(1-a)*(1-b);
    return ret;
}
int main() {
    scanf("%lf %lf",&a,&b);
    a/=100;b/=100;
    memset(dp,-1,sizeof(dp));
    printf("%.6lf\n",dfs(0,0,0));
    return 0;
}
