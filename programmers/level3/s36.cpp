// 배달
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[55];
vector<int> cost[55];

bool check[55];

int T[55];

// 다익스트라
// 1. 최단거리가 확정되지 않은 정점을 구한다.
// 2. 위에서 구한 정점에서 퍼져나간다.
int solution(int N, vector<vector<int>> road, int K) {
    int answer = N;
    
    int M=road.size();
    
    for(int i=0;i<M;i++) {
      int a=road[i][0], b=road[i][1], c=road[i][2];
      
      graph[a].push_back(b);
      graph[b].push_back(a);
      
      cost[a].push_back(c);
      cost[b].push_back(c);
    }
    
    for(int i=1;i<=N;i++) T[i]=987654321;
    T[1]=0; // 시작정점
    
    for(int i=1;i<=N;i++) {
      int min_val=987654321,min_idx=-1;
      
      for(int j=1;j<=N;j++) {
        if(!check[j] && min_val>T[j]) {
          min_val=T[j];
          min_idx=j;
        }
      }
      
      check[min_idx]=true;
      
      for(int j=0;j<graph[min_idx].size();j++) {
        int next=graph[min_idx][j];
        int cost2=cost[min_idx][j];
        
        if(T[next] > min_val+cost2) {
          T[next]=min_val+cost2;
        }
      }
    }
    
    // T[i] -> 2~N 까지의 요소는 1~N까지의 최단거리를 저장
    for(int i=2;i<=N;i++) {
      if(T[i]>K) answer--;  // 배달할 수 없는 마을일 경우 -1
    }
    
    return answer;
}

int main() {

    int N=5;
    vector<vector<int>> road={{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
    int K=3;

    int result=solution(N,road,K);
    printf("%d\n",result);

    return 0;
}