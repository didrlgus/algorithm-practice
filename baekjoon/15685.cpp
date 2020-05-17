// 드래곤 커브
#include<bits/stdc++.h>

using namespace std;

int n;
bool check[110][110];

int dy[]={0,-1,0,1};
int dx[]={1,0,-1,0};

struct p {
    int x,y,d,g;
};

int main() {

    vector<vector<int>> v[4];
    scanf("%d",&n);
    
    vector<p> dc;
    for(int i=0;i<n;i++) {
        int x,y,d,g;
        scanf("%d %d %d %d",&x,&y,&d,&g);
        dc.push_back({x,y,d,g});
    }

    for(int i=0;i<4;i++) {      // 0세대 채우기
        vector<int> v2;
        v2.push_back(i);    
        v[i].push_back(v2);     // 방향 0(->)의 0세대
    }

    for(int i=0;i<4;i++) {      // 각 방향마다, 1~10세대 채우기
        for(int j=1;j<=10;j++) {
            vector<int> vv=v[i][j-1];
            for(int k=vv.size()-1;k>=0;k--) {
                vv.push_back((vv[k]+1)%4);
            }
            v[i].push_back(vv);
        }
    }

    for(int i=0;i<dc.size();i++) {
        int x=dc[i].x,y=dc[i].y,d=dc[i].d,g=dc[i].g;
        check[y][x]=true;

        int ny=y,nx=x;
        for(int j=0;j<v[d][g].size();j++) {
            ny+=dy[v[d][g][j]];
            nx+=dx[v[d][g][j]];

            if(ny<0||nx<0||ny>100||nx>100) continue;
            check[ny][nx]=true;
        }
    }
    int cnt=0;
    for(int i=0;i<100;i++) {
        for(int j=0;j<100;j++) {
            if(check[i][j] && check[i+1][j] && check[i][j+1] && check[i+1][j+1]) cnt++;
        }
    }
    printf("%d\n",cnt);
}