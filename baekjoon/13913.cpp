// 13913. 숨바꼭질 4
#include<bits/stdc++.h>

using namespace std;

int a,b;
bool visited[100005];
int parent[100005];
queue<int> q;

int level;
vector<int> v;
void bfs(int y) {
    visited[y]=true;
    q.push(y);

    while(!q.empty()) {
        int size=q.size();
        while(size--) {
            y=q.front(); q.pop();

            if(y==b) {
                printf("%d\n",level);
                int cur=b;
                v.push_back(b);
                while(cur!=a) {             // 최상위 노드가 아닐때까지
                    v.push_back(parent[cur]);
                    cur=parent[cur];
                }

                for(int i=v.size()-1;i>=0;i--) printf("%d ",v[i]);
                return;
            }

            if(y-1>=0 && !visited[y-1]) {
                visited[y-1]=true;
                parent[y-1]=y;
                q.push(y-1);
            }
            if(y+1<=100000 && !visited[y+1]) {
                visited[y+1]=true;
                parent[y+1]=y;
                q.push(y+1);
            }
            if(y*2<=100000 && !visited[y*2]) {
                visited[y*2]=true;
                parent[y*2]=y;
                q.push(y*2);
            }
        }
        level++;
    }
}


int main() {
    scanf("%d %d",&a,&b);

    bfs(a);

    return 0;
}