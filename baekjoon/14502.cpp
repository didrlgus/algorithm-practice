// 연구소
#include<bits/stdc++.h>

using namespace std;

int n,m;
int arr[15][15], tmp_arr[15][15];
bool visited[15][15];
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
queue<pair<int,int>> virus;
vector<pair<int,int>> v1;
vector<int> v2;
int t_cnt;
int mx=-987654321;

int bfs() {
    fill(&visited[0][0],&visited[0][0]+15*15,0);
    queue<pair<int,int>> tmp=virus;
    
    int cnt=0;
    while(!tmp.empty()) {
        int y=tmp.front().first,x=tmp.front().second;
        tmp.pop();

        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];

            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(!visited[ny][nx]&&tmp_arr[ny][nx]==0) {
                visited[ny][nx]=true;
                cnt++;
                tmp.push({ny,nx});
            }
        }
    }

    return t_cnt-cnt;
}

void combi(int here) {
    if(v2.size()==3) {
        for(int i=0;i<15;i++) {
            for(int j=0;j<15;j++) tmp_arr[i][j]=arr[i][j];
        }
        for(auto iter:v2) tmp_arr[v1[iter].first][v1[iter].second]=1;

        mx=max(mx,bfs());

        return;
    }
    for(int i=here+1;i<(int)v1.size();i++) {
        v2.push_back(i);
        combi(i);
        v2.pop_back();
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==2) virus.push({i,j});
            if(arr[i][j]==0) {
                v1.push_back({i,j});
                t_cnt++;
            }
        }
    }
    combi(-1);
    printf("%d\n",mx-3);

    return 0;
}