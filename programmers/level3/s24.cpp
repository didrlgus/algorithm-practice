// 블록 이동하기
#include<bits/stdc++.h>

using namespace std;

int dy[]={0,1,0,-1};            // 동,남,서,북
int dx[]={1,0,-1,0};

int ry[]={-1,1,1,-1};           // 회전 시 체크해야할 위치 구하기 위함
int rx[]={1,1,-1,-1};

bool visited[110][110][4];      // y,x dir
queue<pair<pair<int,int>, int>> q;
int n;

bool check(int y,int x) {
    if(y<0 || x<0 || y>=n || x>=n) return false;
    return true;
}

int bfs(int y,int x,vector<vector<int>> board) {
    visited[y][x][0]=true;
    q.push({{y,x},0});
    int time=0;

    while(!q.empty()) {
        int size=q.size();

        while(size--) {
            y=q.front().first.first,x=q.front().first.second;
            int dir=q.front().second;
            int yy=y+dy[dir], xx=x+dx[dir];
            
            q.pop();

            if((y==n-1 && x==n-1) || (yy==n-1 && xx==n-1)) return time;

            // 상하좌우 이동
            for(int i=0;i<4;i++) {
                int ny=y+dy[i], nx=x+dx[i];
                int nyy=yy+dy[i], nxx=xx+dx[i];

                if(!check(ny,nx) || !check(nyy,nxx)) continue;          // 영역 체크
                if(board[ny][nx]==1 || board[nyy][nxx]==1) continue;    // 벽 체크 
                if(!visited[ny][nx][dir]) {
                    visited[ny][nx][dir]=true;
                    q.push({{ny,nx},dir});
                }
            }

            // 3    3    0
            // 2  (y,x)  0
            // 2    1    1
            // 첫번째 요소 회전 (yy,xx 이동)
            for(int i=1;i<4;i+=2) {     // i==1 -> 시계방향, i==3 -> 반시계 방향
                int ndir=(dir+i)%4;
                int nyy=y+dy[ndir];
                int nxx=x+dx[ndir];
                
                int tmp=(i==1)?ndir:dir;
                int nry=y+ry[tmp];
                int nrx=x+rx[tmp];

                if(!check(nyy,nxx) || !check(nry,nrx)) continue;
                if(board[nyy][nxx]==1 || board[nry][nrx]==1) continue;
                if(!visited[y][x][ndir]) {
                    visited[y][x][ndir]=true;
                    q.push({{y,x},ndir});
                }
            }

            // 두번째 요소 회전 (y,x 이동)
            dir=(dir+2)%4;  // dir 반대로 반전
            for(int i=1;i<4;i+=2) {
                int ndir=(dir+i)%4;
                int ny=yy+dy[ndir];
                int nx=xx+dx[ndir];

                int tmp=(i==1)?ndir:dir;
                int nry=yy+ry[tmp];
                int nrx=xx+rx[tmp];

                ndir=(ndir+2)%4;        // 기준은 y,x여야 하므로 다시 반전시킴, 바꾸지 않으면 서로 다른 기준의 같은 방문이 생길 수 있음
                
                if(!check(ny,nx) || !check(nry,nrx)) continue;
                if(board[ny][nx]==1 || board[nry][nrx]==1) continue;
                if(!visited[ny][nx][ndir]) {
                    visited[ny][nx][ndir];
                    q.push({{ny,nx},ndir});
                }
            }
        }
        time++;
    }

    return -1;
}
 
int solution(vector<vector<int>> board) {
    int answer = 0;
    n=board.size();
    answer=bfs(0,0,board);

    return answer;
}

int main() {

    vector<vector<int>> board={{0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, 
            {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}};

    int result=solution(board);
    printf("%d\n",result);

    return 0;
}