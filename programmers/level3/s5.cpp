// 네트워크
#include <string>
#include <vector>

using namespace std;

bool visited[210];

void dfs(int sv,vector<vector<int>> computers) {
    // 시작 정점 방문
    visited[sv]=true;

    for(int i=0;i<computers[sv].size();i++) {
        if(!visited[i] && computers[sv][i]) {
            dfs(i,computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0;i<computers.size();i++) {
        if(!visited[i]) {
            dfs(i,computers);
            answer++;
        }
    }

    return answer;
}

int main() {

    int n=3;
    vector<vector<int>> computers={{1,1,0},{1,1,0},{0,0,1}};
    int result=solution(n,computers);
    printf("%d\n",result);

    return 0;
}