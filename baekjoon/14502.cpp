// 연구소
#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> v1;       // 좌표 저장
vector<int> v2;                 // 좌표의 인덱스 저장

int arr[10][10];
int tmp[10][10];
int n,m;

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
int visited[10][10];
queue<pair<int,int>> q;
int mx=-1;

void bfs(int y,int x) {
    visited[y][x]=1;
    q.push({y,x});

    while(!q.empty()) {
        tie(y,x)=q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int ny=y+dy[i], nx=x+dx[i];

            if(ny<0 || nx<0 || ny>=n || nx>=m) continue;

            if(!visited[ny][nx] && tmp[ny][nx]==0) {
                visited[ny][nx]=visited[y][x]+1;
                q.push({ny,nx});
                tmp[ny][nx]=2;
            }
        }
    }
}

void func(int here,vector<int> &v2) {
    if(v2.size()==3) {
        fill(&tmp[0][0],&tmp[0][0]+10*10,0);
        fill(&visited[0][0],&visited[0][0]+10*10,0);

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) tmp[i][j]=arr[i][j];
        }

        for(int i=0;i<v2.size();i++) {
            int y=v1[v2[i]].first, x=v1[v2[i]].second;

            tmp[y][x]=1;    // 벽 채우기
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && tmp[i][j]==2) {
                    bfs(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(tmp[i][j]==0) cnt++;
            }
        }

        mx=max(mx,cnt);
        return;
    }
    for(int i=here+1;i<v1.size();i++) {
        v2.push_back(i);
        func(i,v2);
        v2.pop_back();
    }
}

int main() {

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);

            if(arr[i][j]==0) v1.push_back({i,j});   // 빈칸의 좌표 저장
        }
    }

    func(-1,v2);

    printf("%d\n",mx);
}