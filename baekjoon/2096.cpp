// 내려가기
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,mx=-INF,mn=INF;
vector<int> dp1,dp2,dp3,dp4;
int main() {
    scanf("%d",&n);
    for(int j=0;j<3;j++) {
        int a;scanf("%d",&a);
        dp1.push_back(a);dp3.push_back(a);
    }
    for(int i=1;i<n;i++) {
        for(int j=0;j<3;j++) {
            int a;scanf("%d",&a);
            dp2.push_back(a);dp4.push_back(a);
            if(j==0) {
                dp2[j]+=max(dp1[0],dp1[1]);
                dp4[j]+=min(dp3[0],dp3[1]);
            } else if(j==1) {
                dp2[j]+=max(dp1[0],max(dp1[1],dp1[2]));
                dp4[j]+=min(dp3[0],min(dp3[1],dp3[2]));
            } else {
                dp2[j]+=max(dp1[1],dp1[2]);
                dp4[j]+=min(dp3[1],dp3[2]);
            }
        }
        dp1=dp2;dp3=dp4;
        dp2.clear();dp4.clear();
    }
    mx=max(dp1[0],max(dp1[1],dp1[2]));
    mn=min(dp3[0],min(dp3[1],dp3[2]));
    printf("%d %d\n",mx,mn);
    return 0;
}