// 자두나무
#include<bits/stdc++.h>

using namespace std;

int t,w;
int arr[1010];
int dp[3][1010][35];

// 현재 나무에서 특정 시간동안 특정거리만큼 움직였을 때 얻을 수 있는 자두의 최대개수를 반환하는 함수
int dfs(int current_tree,int time,int dist) {
    if(time==t) return 0;
    if(dp[current_tree][time][dist]!=-1) return dp[current_tree][time][dist];
    
    int& ret=dp[current_tree][time][dist];
    int cnt=(arr[time]==current_tree);
    int next_tree=(current_tree==1)?2:1;

    if(w>dist) ret=max(dfs(next_tree,time+1,dist+1)+!cnt,dfs(current_tree,time+1,dist)+cnt);
    else ret=dfs(current_tree,time+1,dist)+cnt;
    return ret;
}

int main() {

    scanf("%d %d",&t,&w);
    for(int i=0;i<t;i++) scanf("%d",&arr[i]);
    
    fill(&dp[0][0][0],&dp[0][0][0]+3*1010*35,-1);
    printf("%d\n",dfs(1,0,0));      // 나무(1,2), 시간, 이동가능 거리

    return 0;
}