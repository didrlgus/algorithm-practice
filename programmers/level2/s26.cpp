// 땅따먹기
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int dp[100010][10];

int solution(vector<vector<int>> land) {
    int answer = 0;

    for(int i=0;i<4;i++) {
        dp[0][i]=land[0][i];
    }
    
    // 1 2 3 5
    // 5 6 7 8
    // 4 3 2 1

    // dp[i][j]=max(dp[i][j],dp[i-1][k]+land[i][j])
    for(int i=1;i<land.size();i++) {    // 행
        for(int j=0;j<4;j++) {
            for(int k=0;k<4;k++) {
                if(j!=k) {
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+land[i][j]);
                }
            }
        }
    }

    for(int i=0;i<4;i++) answer=max(answer,dp[land.size()-1][i]);

    return answer;
}

int main() {

    vector<vector<int>> land={{1,2,3,5},{5,6,7,8},{4,3,2,1}};
    int result=solution(land);
    printf("%d\n",result);

    return 0;
}