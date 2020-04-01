// 14226. 이모티콘
#include<cstdio>
#include<queue>

using namespace std;

struct p {
    int y;
    int x;
};

int n;
queue<p> q;
int visited[1005][1005];
int min_=987987987;

void bfs(int s,int c) {
    // 시작점 큐에 저장
    visited[s][c]=1;
    q.push({s,c});

    int level=1;

    while(!q.empty()) {
        int size=q.size();

        while(size--) {
            int y=q.front().y;  // screen
            int x=q.front().x;  // clip

            q.pop();
            
            // 1번 조건
            if(!visited[y][y]) {
                visited[y][y]=level;
                q.push({y,y});
            }

            // 2번 조건
            if(y+x<=n && !visited[y+x][x]) {
                visited[y+x][x]=level;
                q.push({y+x,x});
            }

            // 3번 조건
            if(y-1>=0 && !visited[y-1][x]) {
                visited[y-1][x]=level;
                q.push({y-1,x});
            }
        }
        level++;
    }

    for(int i=0;i<n;i++) {
        if(visited[n][i]) {
            min_=min(min_,visited[n][i]);
        }
    }

    printf("%d\n",min_);
}

int main() {

    scanf("%d",&n);

    bfs(1,0);

    return 0;
}