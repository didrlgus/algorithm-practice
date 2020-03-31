// 13913. 숨바꼭질 4
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int n,k;
queue<int> q;
bool visited[100005];
int parent[100005];
vector<int> v;

void bfs(int current) {
    // 시작점 큐에 추가
    visited[current]=true;
    q.push(current);

    int t=0;

    while(!q.empty()) {
        int size=q.size();

        while(size--) {
            int front=q.front();
            q.pop();

            if(front==k) {
                printf("%d\n",t);

                int cur=front;

                v.push_back(cur);
                while(cur!=n) {
                    v.push_back(parent[cur]);
                    cur=parent[cur];
                }

                for(int i=v.size()-1;i>=0;i--) printf("%d ",v[i]);
            }

            if(front-1>=0 && !visited[front-1]) {
                visited[front-1]=true;
                q.push(front-1);
                parent[front-1]=front;
            }

            if(front+1<=100000 && !visited[front+1]) {
                visited[front+1]=true;
                q.push(front+1);
                parent[front+1]=front;
            }

            if(front*2<=100000 && !visited[front*2]) {
                visited[front*2]=true;
                q.push(front*2);
                parent[front*2]=front;
            }
        }

        t++;
    }
}

int main() {

    scanf("%d %d",&n,&k);

    bfs(n);

    return 0;
}