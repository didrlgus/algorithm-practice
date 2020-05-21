// 외판원 순회
#include<bits/stdc++.h>

using namespace std;

const int INF=987654321;
int n;
int arr[20][20];
int dp[20][1<<16];             

// dp[current][visited]
// current에서 시작하여 visited만큼 방문했을 때 거리의 최소값 저장
int dfs(int current,int visited) {
    if(visited==(1<<n)-1) {                                     // 모든 정점을 탐색한 경우
        if(arr[current][0]) return arr[current][0];
        else return INF;
    }
    int& ret=dp[current][visited];
    if(ret!=-1) return ret;                                     // 이미 방문한 정점일 경우 dp에 저장된 최소 거리를 반환
    ret=INF;

    for(int i=0;i<n;i++) {
        if(!arr[current][i]) continue;
        if(visited&(1<<i)) continue;                             // 다음 정점이 이미 visited에 포함된 경우
        ret=min(ret,dfs(i,visited|(1<<i))+arr[current][i]);
    }
    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    fill(&dp[0][0],&dp[0][0]+20*(1<<16),-1);
    printf("%d\n",dfs(0,1));                                    // 0부터 시작, 방문 표시
    
    return 0;
}