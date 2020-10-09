// 침략자 진아
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,cnt,tmp_cnt,dy[]={0,0,1,-1},dx[]={1,-1,0,0},ret=INF;
bool arr[25][25],visited[25][25];
vector<int> candi,v;
queue<pair<int,int>> q,empty_q;
int bfs() {
    int level=1;
    while(!q.empty()) {
        int size=(int)q.size();
        while(size--) {
            int y=q.front().first,x=q.front().second;q.pop();
            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];
                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                if(!visited[ny][nx]) {
                    visited[ny][nx]=true;
                    q.push({ny,nx});
                    if(arr[ny][nx]) tmp_cnt--;
                    if(tmp_cnt==0) return level;
                }
            }
        }
        level++;
    }
    return INF;
}
void combi(int here) {
    if((int)v.size()==2) {
        memset(visited,0,sizeof(visited));
        tmp_cnt=cnt;
        q=empty_q;
        for(auto it:v) {
            int y=candi[it]/100,x=candi[it]%100;
            q.push({y,x});
            visited[y][x]=true;
        }
        ret=min(ret,bfs());
        return;
    }
    for(int i=here+1;i<(int)candi.size();i++) {
        v.push_back(i);
        combi(i);
        v.pop_back();
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%1d",&arr[i][j]);
            if(arr[i][j]) cnt++;
            else candi.push_back(100*i+j);
        }
    }
    combi(-1);
    printf("%d\n",ret);
    return 0;
}