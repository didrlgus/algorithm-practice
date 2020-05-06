// 인구 이동
#include<bits/stdc++.h>

using namespace std;

int n,l,r;
int arr[55][55];

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
queue<pair<int,int>> q;
vector<vector<pair<int,int>>> v;
bool visited[55][55];

vector<pair<int,int>> bfs(int y,int x) {
    vector<pair<int,int>> u;            // 연합의 좌표
    visited[y][x]=true;
    q.push({y,x});
    u.push_back({y,x});

    while(!q.empty()) {
        tie(y,x)=q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];

            if(ny<0||nx<0||ny>=n||nx>=n) continue;
            if(!visited[ny][nx] && (abs(arr[y][x]-arr[ny][nx])>=l && abs(arr[y][x]-arr[ny][nx])<=r)) {
                visited[ny][nx]=true;
                q.push({ny,nx});
                u.push_back({ny,nx});
            }
        }
    }

    return u;
}

int main() {

    scanf("%d %d %d",&n,&l,&r);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
        }
    }

    int t=0;
    while(true) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {   
                vector<pair<int,int>> r=bfs(i,j);

                if(r.size()>1) v.push_back(r);      // 연합이 있는 경우 v에 저장
            }
        }
        if(v.size()==0) break;                      // 연합이 없다면 break
        t++;

        for(int i=0;i<v.size();i++) {
            int sum=0,avg=0;
            for(auto iter:v[i]) sum+=arr[iter.first][iter.second];
            avg=sum/v[i].size();
            for(auto iter:v[i]) arr[iter.first][iter.second]=avg;
        }

        fill(&visited[0][0],&visited[0][0]+55*55,0);
        v.clear();     
    }
        
    printf("%d\n",t);

    return 0;
}