// 숨바꼭질 5
#include<bits/stdc++.h>

using namespace std;

int a,b;
queue<int> q;

int dx[]={-1,1,0};      
int dm[]={1,1,2};           // -1,+1,*2

bool visited[2][500010];    // 홀짝,범위

int bfs(int n) {
    visited[0][n]=true;
    q.push(n);
    int level=1;
    while(!q.empty()) {
        b+=level;
        if(b>500000) break;
        if(visited[level%2][b]) return level;           // 이전 단계에 이미 b가 visited 됐을 경우
        int size=q.size();
        while(size--) {
            n=q.front(); q.pop();

            for(int i=0;i<3;i++) {
                int na=(n+dx[i])*dm[i];

                if(na<0 || na>500000) continue;
                if(na==b) return level;                 // 처음 b가 나와서 일치하는 경우

                if(!visited[level%2][na]) {
                    visited[level%2][na]=true;
                    q.push(na);
                }
            }
        }
        level++;
    }
    return -1;
}

int main() {

    scanf("%d %d",&a,&b);

    if(a==b) {
        printf("0\n");
        return 0;
    }
    int result=bfs(a);
    printf("%d\n",result);

    return 0;
}