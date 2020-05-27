// 뮤탈리스크
#include<bits/stdc++.h>
using namespace std;

int n,arr[5],level;
int permu[6][3]={{9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,9,3},{1,3,9}};
bool visited[65][65][65];
struct p {
    int a,b,c;
};
int bfs(int a,int b,int c) {
    queue<p> q;
    q.push({a,b,c});
    visited[a][b][c]=true;
    while(!q.empty()) {
        int size=q.size();
        while(size--) {
            a=q.front().a,b=q.front().b,c=q.front().c;q.pop();
            if(a==0&&b==0&&c==0) return level;
            for(int i=0;i<6;i++) {
                int d=max(0,a-permu[i][0]),e=max(0,b-permu[i][1]),f=max(0,c-permu[i][2]);
                if(!visited[d][e][f]) {
                    visited[d][e][f]=true;
                    q.push({d,e,f});
                }
            }
        }
        level++;
    }
    return -1;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("%d\n",bfs(arr[0],arr[1],arr[2]));
    return 0;
}