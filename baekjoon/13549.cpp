// 13549. 숨바꼭질 3
#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int n,k;
int visited[100005];

struct p {
    int current, time;
};

queue<p> q;

int min_=987987987;

void bfs(int c, int t) {
    // 시작점 큐에 삽입
    visited[c]=t;
    q.push({c,t});

    while(!q.empty()) {
        int fc=q.front().current;
        int ft=q.front().time;

        q.pop();

        if(fc==k) {
            min_=min(min_,ft);
        }

        if(fc+1<=100000 && visited[fc+1]>ft+1) {
            visited[fc+1]=ft+1;
            q.push({fc+1,ft+1});
        }

        if(fc-1>=0 && visited[fc-1]>ft+1) {
            visited[fc-1]=ft+1;
            q.push({fc-1,ft+1});
        }

        if(fc*2<=100000 && visited[fc*2]>ft) {
            visited[fc*2]=ft;
            q.push({fc*2,ft});
        }
    }

    printf("%d\n",min_);
}

int main() {

    scanf("%d %d",&n,&k);

    for(int i=0;i<100005;i++) visited[i]=987987987;

    bfs(n,0);

    return 0;
}