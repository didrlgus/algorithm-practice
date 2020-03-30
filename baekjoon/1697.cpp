// 1697. 숨바꼭질
#include<cstdio>
#include<queue>
using namespace std;

int n,k;
const int MAX = 100000;

queue<int> q;
bool visited[100005];

int bfs(int c) {
    // 시작점 큐에 삽입
    visited[c]=true;
    q.push(c);

    int time=0;

    while(!q.empty()) {
        int size=q.size();
        
        while(size--) {
            int front=q.front();
            if(front==k) return time;
            q.pop();

            if(front-1>=0 && !visited[front-1]) {
                visited[front-1]=true;
                q.push(front-1);
            }

            if(front+1<=MAX && !visited[front+1]) {
                visited[front+1]=true;
                q.push(front+1);
            }

            if(front*2<=MAX && !visited[front*2]) {
                visited[front*2]=true;
                q.push(front*2);
            }
        }
        time++;
    }
    return 0;
}

int main() {

    scanf("%d",&n);
    scanf("%d",&k);

    int result=bfs(n);

    printf("%d\n",result);

    return 0;
}