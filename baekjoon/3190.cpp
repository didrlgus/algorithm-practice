// 뱀
#include<bits/stdc++.h>

using namespace std;

int n,a,b;
queue<pair<int,char>> q;
deque<pair<int,int>> dq;

char arr[110][110];
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};
int t=0;
bool flag;

void dfs(int y,int x,int dir) {
    if(flag) return;

    int ndir=dir;
    if(t==q.front().first) {                    // 방향을 바꾸는 부분
        if(q.front().second=='L') {
            ndir=dir-1<0?3:dir-1;
        } else {
            ndir=dir+1>3?0:dir+1;
        }
        q.pop();
    } 
    
    int ny=y+dy[ndir],nx=x+dx[ndir];
    t++;
    if(ny<0||nx<0||ny>=n||nx>=n) flag=true;
    if(arr[ny][nx]=='S') flag=true;
    if(flag) return;

    if(arr[ny][nx]=='.') {
        arr[dq.back().first][dq.back().second]='.';
        dq.pop_back();
        arr[ny][nx]='S';
        dq.push_front({ny,nx});
    } else if(arr[ny][nx]=='A') {
        arr[ny][nx]='S';
        dq.push_front({ny,nx});
    }
    
    dfs(ny,nx,ndir);
}

int main() {
    fill(&arr[0][0],&arr[0][0]+110*110,'.');
    scanf("%d",&n);
    scanf("%d",&a);
    for(int i=0;i<a;i++) {
        int c,d;
        scanf("%d %d",&c,&d);
        arr[c-1][d-1]='A';
    }
    scanf("%d",&b);
    for(int i=0;i<b;i++) {
        int c;char d;
        scanf("%d %c",&c,&d);
        q.push({c,d});
    }

    arr[0][0]='S';
    dq.push_front({0,0});
    dfs(0,0,0);
    printf("%d\n",t);

    return 0;
}