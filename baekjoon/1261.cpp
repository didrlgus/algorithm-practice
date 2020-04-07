// 1261. 알고스팟
#include<cstdio>
#include<queue>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

int n,m;

char a[105][105];
bool visited[105][105];

// 우선순위 큐를 이용한 bfs 문제
priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

int bfs() {
    // 시작점 큐에 삽입
    visited[0][0]=true;
    pq.push({0,{0,0}});  // {cnt,{y,x}}

    while(!pq.empty()) {
        int y=pq.top().second.first;
        int x=pq.top().second.second;
        int cnt=pq.top().first;

        pq.pop();

        if(y==n-1 && x==m-1) return cnt;
        
        for(int i=0;i<4;i++) {
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny<0 || nx<0 || ny>=n || nx>=m) continue;

            if(!visited[ny][nx]) {
                visited[ny][nx]=true;

                if(a[ny][nx]=='1') pq.push({cnt+1,{ny,nx}});
                else pq.push({cnt,{ny,nx}});
            }
        }
    }

    return 0;
}

int main() {

    scanf("%d %d",&m,&n);

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++) {
            a[i][j]=s.at(j);
        }
    }

    int result=bfs();

    printf("%d\n",result);

    return 0;
}