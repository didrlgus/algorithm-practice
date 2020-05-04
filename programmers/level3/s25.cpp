// 거스름돈
#include <bits/stdc++.h>

using namespace std;

vector<int> d1;
vector<int> d2;

int solution(int n, vector<int> money) {
    int answer = 0;
    sort(money.begin(),money.end());
    d1.resize(n+1);
    d2.resize(n+1);
    
    for(int i=0;i<=n;i+=money[0]) d1[i]=1;
    
    // dp[i][j] = i번째 동전까지 사용하여 거스름돈 j를 만드는 경우의 수
    // dp[i][j] = dp[i-1][j]+dp[i][j-money[i]]
    // 2차원 배열의 메모리공간 낭비를 줄이기 위해 1차원배열 2개로 표현
    // dp[i][j]를 구하는데 dp[i-1][j]만 필요, dp[i-2][j],dp[i-3][j]...등은 필요x
    for(int i=1;i<money.size();i++) {
        fill(d2.begin(),d2.end(),0);

        for(int j=0;j<=n;j++) {
            d2[j]=d1[j];
            if(j>=money[i]) d2[j]+=d2[j-money[i]];
        }
        d1=d2;
    }

    answer=d1[n]%1000000007;

    return answer;
}

int main() {
    int n=5;
    vector<int> money={1,2,5};
    int result=solution(n,money);
    printf("%d\n",result);

    return 0;
}
