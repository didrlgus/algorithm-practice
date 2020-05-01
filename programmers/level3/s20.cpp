// 보행자 천국
#include<bits/stdc++.h>

using namespace std;

int MOD = 20170805;

int d[510][510];    // down
int l[510][510];    // left

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> city_map) {
    int answer = 0;

    fill(&d[0][0],&d[0][0]+510*510,0);
    fill(&l[0][0],&l[0][0]+510*510,0);

    d[1][1]=l[1][1]=1;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(city_map[i-1][j-1]==0) {            // city_map은 0,0부터 시작 / d,l은 1,1부터 시작(배열 요소에 -1하는 부분으로 인해)
                d[i][j]+=(d[i-1][j]+l[i][j-1])%20170805;
                l[i][j]+=(d[i-1][j]+l[i][j-1])%20170805;
            } else if(city_map[i-1][j-1]==1) {
                d[i][j]=0;
                l[i][j]=0;
            } else {
                d[i][j]+=d[i-1][j]%20170805;
                l[i][j]+=l[i][j-1]%20170805;
            }
        }
    }
    answer=d[n][m];     // d[n][m], l[n][m] 둘 중 하나 리턴

    return answer;
}

int main() {

    int n=3,m=6;
    vector<vector<int>> city_map={{0, 2, 0, 0, 0, 2},{0, 0, 2, 0, 1, 0},{1, 0, 0, 2, 2, 0}};
    int result=solution(n,m,city_map);
    printf("%d\n",result);
}