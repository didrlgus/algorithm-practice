// 종이자르기
#include<bits/stdc++.h>

using namespace std;

int n,m,k;
vector<pair<int,int>> v;
int arr[210][210];
int visited[210][210];

queue<pair<int,int>> q;

int dy[]={0,0,1,-1},dx[]={1,-1,0,0};

int max_=-987987987;

int bfs(int y,int x) {
    // 시작점 방문
    visited[y][x]=1;
    q.push({y,x});

    int sum=1;
    while(!q.empty()) {
        tie(y,x)=q.front();
        q.pop();
        
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];

            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;

            if(!visited[ny][nx] && arr[ny][nx]==0) {
                visited[ny][nx]=visited[ny][nx]+1;
                q.push({ny,nx});
                sum++;
            }
        }
    }
    return sum;
}

int main() {

    scanf("%d %d",&m,&n);
    scanf("%d",&k);

    for(int i=0;i<k;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        v.push_back({a,b});
    }

    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++) {
        if(v[i].first==0) {         // 가로 자르기
            int rCnt=0,rIdx=0;
            while(true) {
                if(arr[rIdx++][0]==0) rCnt++;
                if(rCnt>=v[i].second) break;
            }
            n++;
            for(int j=0;j<210;j++) arr[rIdx][j]=1;
        } else {                    // 세로 자르기
            int cCnt=0,cIdx=0;
            while(true) {
                if(arr[0][cIdx++]==0) cCnt++;
                if(cCnt>=v[i].second) break;
            }
            m++;
            for(int j=0;j<210;j++) arr[j][cIdx]=1;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!visited[i][j] && arr[i][j]==0){
                max_=max(max_,bfs(i,j));
            }
        }
    }

    printf("%d\n",max_);

    return 0;
}