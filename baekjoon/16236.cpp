// 아기 상어
#include<bits/stdc++.h>

using namespace std;

int arr[30][30];
int n;
int r,c;                // 상어의 위치 저장 좌표
int sharkSize=2;        
int eat;                // 상어가 먹은 물고기 양

int visited[30][30];
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
vector<pair<int,pair<int,int>>> result;

vector<pair<int,pair<int,int>>> bfs(int y,int x) {
    fill(&visited[0][0],&visited[0][0]+30*30,0);
    vector<pair<int,pair<int,int>>> v;         // y,x 좌표
    queue<pair<int,int>> q;
    visited[y][x]=1;
    q.push({y,x});

    while(!q.empty()) {
        int size=q.size();
            
        tie(y,x)=q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int ny=y+dy[i], nx=x+dx[i];

            if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
            if(visited[ny][nx] || sharkSize<arr[ny][nx]) continue;
            // arr[ny][nx]이 sharkSize보다 같거나 작은경우
            visited[ny][nx]=visited[y][x]+1;
            q.push({ny,nx});
            if(arr[ny][nx]>0 && arr[ny][nx]<sharkSize) v.push_back({visited[ny][nx]-1,{ny,nx}});           // 현재 상어의 위치에서 최단 거리에 있는 먹을 수 있는 물고기의 거리, 좌표를 저장
        }
    }
    if(v.size()>1) sort(v.begin(),v.end(),less<pair<int,pair<int,int>>>());
    // 잡아먹을 물고기의 거리,위치 반환
    return v;                              
}

int main() {

    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==9) {
                r=i; c=j;
                arr[r][c]=0;
            }
        }
    }
    int t=0;
    while(true) {
        result=bfs(r,c);
        if(result.size()==0) break;

        r=result[0].second.first,c=result[0].second.second;     // 상어 위치 초기화
        arr[r][c]=0;
        eat++;
        t+=result[0].first;
        if(eat==sharkSize) {
            sharkSize++;
            eat=0;
        }
    }

    printf("%d\n",t);

    return 0;
}