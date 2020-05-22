// 1로 만들기 2
#include<bits/stdc++.h>

using namespace std;

int n;
int dp[1000010];
int arr[1000010];
vector<int> v;
int dfs(int x) {
    if(x==1) return 0;
    if(dp[x]!=-1) return dp[x];
    int tmp=1000010;
    int &ret=dp[x];
    int one=dfs(x-1)+1;
    tmp=x-1;
    if(x%2==0) {
        int two=dfs(x/2)+1;
        if(one>two) {
            one=two;
            tmp=x/2;
        }
    }
    if(x%3==0) {
        int three=dfs(x/3)+1;
        if(one>three) {
            one=three;
            tmp=x/3;
        }
    }

    arr[x]=tmp;
    ret=one;
    return ret;
}
int main() {
    scanf("%d",&n);
    fill(&dp[0],&dp[0]+1000010,-1);
    if(n==1) {
        printf("0\n1\n");
        return 0;
    }
    printf("%d\n",dfs(n));
    printf("%d ",n);
    while (arr[n]!=1) {
        printf("%d ",arr[n]);
        n=arr[n];
    }
    printf("1\n");
    return 0;
}