// 9095. 1, 2, 3 더하기
#include<cstdio>

int dp[15];

int main() {
    int n;
    scanf("%d",&n);

    dp[1]=1;
    dp[2]=2;
    dp[3]=4;

    for(int i=0;i<n;i++) {
        int m;
        scanf("%d",&m);

        for(int j=4;j<=m;j++) {
            dp[j]=dp[j-1]+dp[j-2]+dp[j-3];
        }
        printf("%d\n", dp[m]);
    }
}