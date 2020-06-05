// 모노 디지털 표현
#include<bits/stdc++.h>
using namespace std;
int k,t,n,ret;
set<int> dp[9];
int check(int n) {
    for(int i=1;i<=8;i++) {
        if(dp[i].count(n)) return i;
    }
    return 0;
}
int main() {
    scanf("%d %d",&k,&t);
    int num=0;
    for(int i=1;i<=8;i++) {
        num=num*10+k;
        dp[i].insert(num);
    }
    for(int i=1;i<8;i++) {
        for(int j=1;j<=i;j++) {
            int cnt=i+j;
            if(i+j>8) continue;
            for(auto d1:dp[i]) {
                for(auto d2:dp[j]) {
                    dp[cnt].insert(d1+d2);
                    dp[cnt].insert(abs(d1-d2));
                    dp[cnt].insert(d1*d2);
                    if(d1!=0) dp[cnt].insert(d2/d1);
                    if(d2!=0) dp[cnt].insert(d1/d2);
                }
            }
        }
    }
    while(t--) {
        scanf("%d",&n);
        ret=check(n);
        if(ret) printf("%d\n",ret);
        else printf("NO\n");
    }
    return 0;
}