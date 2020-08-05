// 공통 부분 문자열
#include<bits/stdc++.h>
using namespace std;
int n,m,dp[4005][4005],ret;
string s1,s2;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>s1>>s2;
    n=(int)s1.size(),m=(int)s2.size();
    for(int i=0;i<n;i++) if(s1[i]==s2[0]) dp[i][0]=1;
    for(int j=0;j<m;j++) if(s1[0]==s2[j]) dp[0][j]=1;
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(s1[i]==s2[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
                ret=max(ret,dp[i][j]);
            }
        }
    }
    cout<<ret<<'\n';
    return 0;
}