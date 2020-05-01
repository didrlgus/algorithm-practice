// 등굣길
#include<bits/stdc++.h>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    int arr[n][m];
    fill(&arr[0][0],&arr[0][0]+n*m,0);

    for(int i=0;i<puddles.size();i++) arr[puddles[i][1]-1][puddles[i][0]-1]=-1;
    
    int a=1;
    for(int i=0;i<n;i++) {
        if(arr[i][0]!=-1) arr[i][0]=a;
        else a=-1;
    }
    int b=1;
    for(int j=0;j<m;j++) {
        if(arr[0][j]!=-1) arr[0][j]=b;
        else b=-1;
    }

    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(arr[i][j]!=-1) {
                if(arr[i-1][j]==-1 && arr[i][j-1]==-1) {
                    arr[i][j]=0;
                } else if(arr[i-1][j]==-1 && arr[i][j-1]!=-1) {
                    arr[i][j]=arr[i][j-1]%1000000007;
                } else if(arr[i-1][j]!=-1 && arr[i][j-1]==-1) {
                    arr[i][j]=arr[i-1][j]%1000000007;
                } else {
                    arr[i][j]=(arr[i][j-1]+arr[i-1][j])%1000000007;
                }
            }
        }
    }

    answer=arr[n-1][m-1];
    return answer;
}

int main() {

    int m=4,n=3;
    vector<vector<int>> puddles={{2,2}};
    int result=solution(m,n,puddles);
    printf("%d\n",result);

    return 0;
}