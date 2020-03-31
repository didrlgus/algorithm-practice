// 1525. 퍼즐
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<map>
#define p pair<int, int>

using namespace std;

int dest=123456789;
int st;

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

queue<int> q;
map<int,int> visited;

void bfs() {
    // 큐에 첫번째 요소 삽입
    visited[st]=1;      // visited.insert({st,1}); 와 동일
    q.push(st);

    int cnt=0;

    while(!q.empty()) {
        int size=q.size();

        while(size--) {
            int front=q.front();
            if(front==dest) {
                printf("%d\n",cnt);
                return;
            }
            q.pop();

            string s=to_string(front);
            int nIdx=s.find('9');   // bfs의 시작점

            int y=nIdx/3;
            int x=nIdx%3;

            for(int i=0;i<4;i++) {
                int nextY=y+dy[i];
                int nextX=x+dx[i];

                if(nextY>=0 && nextX>=0 && nextY<3 && nextX<3) {
                    string tmp=s;

                    swap(tmp[y*3+x], tmp[nextY*3+nextX]);

                    int t=stoi(tmp);

                    if(!visited.count(t)) {
                        visited[t]=cnt+1;
                        q.push(t);
                    }
                }
            }
        }
        cnt++;
    }

    printf("-1\n");
}

int main() {

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            int a;
            scanf("%d",&a);

            if(a==0) a=9;

            st=st*10+a;
        }
    }

    bfs();

    return 0;
}