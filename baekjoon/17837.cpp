// 새로운 게임 2
#include<bits/stdc++.h>

using namespace std;

int n,k;
int arr[15][15];
struct p {
    int y,x,dir;
};
vector<p> chess;
vector<int> status[15][15];

int dy[]={0,0,-1,1};
int dx[]={1,-1,0,0};

bool isExit() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if((int)status[i][j].size()>=4) return true;
        }    
    }
    return false;
}

int change(int dir) {
    if(dir==0) return 1;
    else if(dir==1) return 0;
    else if(dir==2) return 3;
    else return 2;
}

void go(int y,int x,int dir,int idx) {
    int ny=y+dy[dir],nx=x+dx[dir];

    if(ny<0||nx<0||ny>=n||nx>=n||arr[ny][nx]==2) {
        dir=change(dir);
        chess[idx].dir=dir;
        ny=y+dy[dir],nx=x+dx[dir];
        if(ny<0||nx<0||ny>=n||nx>=n||arr[ny][nx]==2) return;    // 또 파란색->방향만 바꿔주고 제자리
    }
    
    // 현재 위치 기준으로 뒤쪽말에 해당하는 부분 찾아서 처리하기
    vector<int> &tmp=status[y][x];
    auto pos=find(tmp.begin(),tmp.end(),idx);
    
    vector<int> bak;
    for(auto it=pos;it!=tmp.end();it++){
        chess[*it].y=ny;                                  // 체스말도 다 새로 옮겨줘야 함
        chess[*it].x=nx;
        bak.push_back(*it);
    }
    tmp.erase(pos,tmp.end());

    if(arr[ny][nx]==1) reverse(bak.begin(),bak.end());      // 빨간색->reverse
    
    for(int el:bak) status[ny][nx].push_back(el);
}

int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<k;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        a--;b--;c--;
        chess.push_back({a,b,c});
        status[a][b].push_back(i);
    }
    
    int turn=0;
    bool flag=false;
    while(turn<=1000) {
        turn++;
        for(int i=0;i<(int)chess.size();i++) {
            int y=chess[i].y,x=chess[i].x,dir=chess[i].dir;
            go(y,x,dir,i);
            
            if(isExit()) {                  // 체스말을 하나하나 옮기면서 4개이상 쌓이면 '바로' 게임 종료
                flag=true;
                break;
            }
        }
        if(flag) break;
    }

    if(flag) printf("%d\n",turn);
    else printf("-1\n");

    return 0;
}