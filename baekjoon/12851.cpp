// 12851. 숨바꼭질 2
#include<bits/stdc++.h>

using namespace std;

int a,b;
bool visited[100010];
queue<int> q;

int level,cnt;
void bfs(int y) {
    visited[y]=true;
    q.push(y);

    while(!q.empty()) {
        int size=q.size();

        while(size--) {
            y=q.front();
            q.pop();
            visited[y]=true;                    // 큐에서 뽑은 다음 바로 경로 저장, 경로를 이부분에서 true시켜주는 예외적인 상황

            if(y==b) cnt++;

            if(y+1<=100000 && !visited[y+1]) {
                q.push(y+1);
            }
            if(y-1>=0 && !visited[y-1]) {
                q.push(y-1);
            }
            if(y*2<=100000 && !visited[y*2]) {
                q.push(y*2);
            }
        }
        if(cnt>0) break;
        level++;
    }
}

int main() {
    scanf("%d %d",&a,&b);

    bfs(a);
    printf("%d\n%d\n",level,cnt);
    return 0;
}