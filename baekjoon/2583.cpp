// 영역 구하기
#include<bits/stdc++.h>

using namespace std;

int a[110][110];
int n,m,K;
int visited[110][110];

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

queue<pair<int,int>> q;
vector<int> v;

int bfs(int y,int x) {
    int sum=1;
    visited[y][x]=1;
    q.push({y,x});

    while(!q.empty()) {
        tie(y,x)=q.front(); q.pop();

        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];

            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if(!visited[ny][nx] && a[ny][nx]==0) {
                visited[ny][nx]=visited[y][x]+1;
                q.push({ny,nx});
                sum++;
            }
        }
    }
    return sum;
}

int main() {

    scanf("%d %d %d",&n,&m,&K);

    for(int i=0;i<K;i++) {
        int b,c,d,e;
        scanf("%d %d %d %d",&b,&c,&d,&e);

        for(int j=c;j<e;j++) {
            for(int k=b;k<d;k++) {
                a[j][k]=1;
            }
        }
    }

    int cnt=0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!visited[i][j] && a[i][j]==0) {
                int r=bfs(i,j);
                v.push_back(r);
                cnt++;
            }
        }
    }

    sort(v.begin(),v.end());

    printf("%d\n",cnt);

    for(int i=0;i<v.size();i++) printf("%d ",v[i]);

    return 0;
}