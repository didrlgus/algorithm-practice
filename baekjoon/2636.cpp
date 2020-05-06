// 치즈
#include<bits/stdc++.h>

using namespace std;

int n,m;
int arr[110][110];

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
bool visited[110][110];
int cnt=0;

vector<pair<int,int>> v;
vector<int> v2;

void dfs(int y,int x) {
    // 시작점 방문
    visited[y][x]=true;
    
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];

        // 경계 체크
        if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
        if(visited[ny][nx]) continue;

        if(arr[ny][nx]==1) {
            visited[ny][nx]=true;
            v.push_back({ny,nx});
        } else {
            dfs(ny,nx);
        }
    }
}

int main() {

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);

            if(arr[i][j]==1) cnt++;
        }
    }

    int t=0,a=0;
    while(true) {
        fill(&visited[0][0],&visited[0][0]+110*110,0);
        dfs(0,0);
        t++;

        for(auto iter:v) arr[iter.first][iter.second]=0;

        cnt-=v.size();
        
        if(cnt<=0) {
            a=v.size();
            break;
        }
        v.clear();
        v2.push_back(cnt);
    }
    
    printf("%d\n",t);
    printf("%d\n",a);

    return 0;
}