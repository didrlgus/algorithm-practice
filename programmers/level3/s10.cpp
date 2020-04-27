// 가장 먼 노드
#include <bits/stdc++.h>

using namespace std;

vector<int> graph[20010];
bool visited[20010];
queue<int> q;
int answer;

void bfs(int start) {
    // 1. 시작정점 방문
    visited[start]=true;
    q.push(start);

    while(!q.empty()) {
        int size=q.size();
        answer=size;

        while(size--) {
            int current=q.front();
            q.pop();

            for(int i=0;i<graph[current].size();i++) {
                int x=graph[current][i];

                if(!visited[x]) {
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {

    for(int i=0;i<edge.size();i++) {
        // 무방향그래프 (인접 리스트)
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    bfs(1);

    return answer;
}

int main() {

    int n=6;
    vector<vector<int>> edge={{3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2}};
    int result=solution(n,edge);
    printf("%d\n",result);

    return 0;
}