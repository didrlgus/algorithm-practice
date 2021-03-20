// 카드 짝 맞추기
#include<bits/stdc++.h>
using namespace std;
const int INF=2e9;
vector<int> kind,v;
vector<vector<int>> tmp_board(4,vector<int>(4,0));
int kind_len,dy[]={0,0,1,-1},dx[]={1,-1,0,0},start_r,start_c,cnt,ret=INF;
pair<int,int> cur_cursor;
map<int,vector<pair<int,int>>> mp;
bool visited[5][5];
bool oob(int y,int x) {
    return y<0||x<0||y>=4||x>=4;
}
int bfs(int y,int x,int dest_y,int dest_x,int idx) {
    queue<pair<int,int>> q;
    visited[y][x]=true;
    q.push({y,x});
    int level=0;
    while(!q.empty()) {
        int size=(int)q.size();
        while(size--) {
            tie(y,x)=q.front();q.pop();
            if(y==dest_y&&x==dest_x) {
                if(idx&1) {
                    tmp_board[cur_cursor.first][cur_cursor.second]=0;
                    tmp_board[y][x]=0;
                }
                cur_cursor.first=y;
                cur_cursor.second=x;
                return level;
            }
            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];
                if(oob(ny,nx)) continue;
                if(!visited[ny][nx]) {
                    visited[ny][nx]=true;
                    q.push({ny,nx});
                }
            }
            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];
                while(!oob(ny,nx)&&!tmp_board[ny][nx]) {
                    ny+=dy[i];
                    nx+=dx[i];
                }
                if(oob(ny,nx)) {
                    ny-=dy[i];
                    nx-=dx[i];
                }
                if(!visited[ny][nx]) {
                    visited[ny][nx]=true;
                    q.push({ny,nx});
                }
            }
        }
        level++;
    }
    return -1;
}
void go(vector<vector<int>>& board) {
    if((int)v.size()==kind_len) {
        int dist=0;
        tmp_board=board;
        cur_cursor={start_r,start_c};
        vector<int> seq,vv;
        for(auto it:kind) {
            seq.push_back(it);
            seq.push_back(it);
        }
        for(auto it:v) {
            vv.push_back(it);
            vv.push_back(it==0?1:0);
        }
        for(int i=0;i<(int)seq.size();i++) {
            memset(visited,false,sizeof(visited));
            int start_y=cur_cursor.first,start_x=cur_cursor.second;
            int dest_y=mp[seq[i]][vv[i]].first,dest_x=mp[seq[i]][vv[i]].second;
            dist+=(bfs(start_y,start_x,dest_y,dest_x,i)+1);
        }
        ret=min(ret,dist);
        return;
    }
    for(int i=0;i<2;i++) {
        v.push_back(i);
        go(board);
        v.pop_back();
    }
}
int solution(vector<vector<int>> board, int r, int c) {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            tmp_board[i][j]=board[i][j];
            if(board[i][j]) {
                kind.push_back(board[i][j]);
                mp[board[i][j]].push_back({i,j});
            }
        }
    }
    start_r=r,start_c=c;
    sort(kind.begin(),kind.end());
    kind.erase(unique(kind.begin(),kind.end()),kind.end());
    kind_len=(int)kind.size();
    do {
        v.clear();
        go(board);
    } while(next_permutation(kind.begin(),kind.end()));
    return ret;
}
int main() {
    vector<vector<int>> board={{1, 0, 0, 3}, {2, 0, 0, 0}, {0, 0, 0, 2}, {3, 0, 1, 0}};
    int r=1,c=0;
    printf("%d\n",solution(board,r,c));
    return 0;
}