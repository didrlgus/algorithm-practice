// 카카오프렌즈 컬러링북
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

bool visited[110][110];

int bfs(int r,int c,vector<vector<int>> picture,int m,int n) {
    queue<pair<int,int>> q;
    // 시작정점 큐에 삽입
    visited[r][c]=true;
    q.push({r,c});
    int num=picture[r][c];
    int cnt=1;

    int dy[]={0,0,1,-1};
    int dx[]={1,-1,0,0};

    while(!q.empty()) {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny<0 || nx<0 || ny>=m || nx>=n) continue;

            if(!visited[ny][nx] && num==picture[ny][nx]) {
                visited[ny][nx]=true;
                q.push({ny,nx});
                cnt++;
            }
        }
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) visited[i][j]=false;
    }

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(!visited[i][j] && picture[i][j]>0) {
                number_of_area++;
                max_size_of_one_area=max(max_size_of_one_area,bfs(i,j,picture,m,n));
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}

int main() {

    int m=6,n=4;

    vector<vector<int>> picture={{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}};
    vector<int> v=solution(m,n,picture);

    printf("%d %d",v[0],v[1]);

    return 0;
}