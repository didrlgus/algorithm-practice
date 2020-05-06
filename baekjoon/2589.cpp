// 보물섬
#include<bits/stdc++.h>

using namespace std;

char arr[55][55];
int n,m;

vector<pair<int,int>> v;

queue<pair<int,int>> q;
bool visited[55][55];

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

int mx=-987654321;

int bfs(int y,int x) {
    visited[y][x]=true;
    q.push({y,x});
    int level=0;

    while(!q.empty()) {
        int size=q.size();

        while(size--) {
            tie(y,x)=q.front();
            q.pop();

            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];

                if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
                if(visited[ny][nx] || arr[ny][nx]=='W') continue;

                visited[ny][nx]=true;
                q.push({ny,nx});
            }
        }
        level++;
    }

    return level-1;
}

int main() {
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf(" %1c",&arr[i][j]);
            if(arr[i][j]=='L') v.push_back({i,j});      // 육지 좌표 저장
        }
    }

    // 모든 육지를 시작점으로 하여 bfs 수행, 시간복잡도는??
    for(auto iter:v) {
        fill(&visited[0][0],&visited[0][0]+55*55,0);
        mx=max(mx,bfs(iter.first,iter.second));
    }
    printf("%d\n",mx);

    return 0;
}