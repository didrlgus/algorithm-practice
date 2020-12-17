// 경주로 건설
#include<bits/stdc++.h>
using namespace std;
struct car {
    int y,x,dir,cost;
};
int n,dy[]={-1,0,1,0},dx[]={0,1,0,-1},ret=987654321;
vector<vector<int>> arr;
queue<car> q;
void bfs(int y,int x) {
    arr[0][0]=1;
    q.push({0,0,5,0});
    while(!q.empty()) {
        car fr=q.front();q.pop();
        if(fr.y==n-1&&fr.x==n-1) {
            ret=min(ret,fr.cost);
            continue;
        }
        for(int i=0;i<4;i++) {
            int ny=fr.y+dy[i],nx=fr.x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=n||arr[ny][nx]==1) continue;
            int new_cost=fr.cost;
            if((fr.y==0&&fr.x==0)||fr.dir==i) new_cost+=100;
            else new_cost+=600;
            if(arr[ny][nx]==0||arr[ny][nx]>=new_cost) {             // arr[ny][nx]을 거치지 않았거나 거쳤지만 더 적은 비용의 방식이 있는경우
                q.push({ny,nx,i,new_cost});
                arr[ny][nx]=new_cost;
            }
        }
    }
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    n=(int)board.size();
    arr=board;
    bfs(0,0);
    answer=ret;
    return answer;
}
int main() {
    vector<vector<int>> board={{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},
        {0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}};
    int val=solution(board);
    printf("%d\n",val);
    return 0;
}