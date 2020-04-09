// 9328. 열쇠
#include<cstdio>
#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

int tc,n,m;

char a[105][105];
bool key[30];
bool visited[105][105];

struct p{
    int y,x;
};

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

void bfs() {
    // 다시 이전 요소로 돌아가기 위한 큐를 하나 더 선언하는 것이 핵심
    queue<p> q1;        // bfs 돌리기 위한 큐
    queue<p> q2[30];    // 대문자의 좌표를 저장하기 위한 큐 배열

    // 시작점(0,0으로 지정) 큐에 삽입
    visited[0][0]=true;
    q1.push({0,0});
    int cnt=0;

    while(!q1.empty()) {
        int y=q1.front().y;
        int x=q1.front().x;

        q1.pop();

        for(int i=0;i<4;i++) {
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny<0 || nx<0 || ny>=n+2 || nx>=m+2) continue;
            if(a[ny][nx]=='*') continue;

            if(!visited[ny][nx]) {
                if(a[ny][nx]=='.') {                                    // 1. '.'
                    visited[ny][nx]=true;
                    q1.push({ny,nx});
                } else if(a[ny][nx]>='A' && a[ny][nx]<='Z') {           // 2. 대문자
                    visited[ny][nx]=true;

                    if(key[a[ny][nx]-'A']) {    // 키가 있는 경우
                        q1.push({ny,nx});
                    } else {                    // 키가 없는 경우
                        q2[a[ny][nx]-'A'].push({ny,nx});
                    }
                } else if(a[ny][nx]>='a' && a[ny][nx]<='z') {           // 3. 소문자
                    visited[ny][nx]=true;

                    if(!key[a[ny][nx]-'a']) {       // 키가 없었을 경우
                        key[a[ny][nx]-'a']=true;    // 키 추가
                        q1.push({ny,nx});

                        while(!q2[a[ny][nx]-'a'].empty()) {
                            q1.push({q2[a[ny][nx]-'a'].front().y, q2[a[ny][nx]-'a'].front().x});
                            q2[a[ny][nx]-'a'].pop();
                        }
                    } else {    // 키가 이미 있을 경우
                        q1.push({ny,nx});
                    }
                } else if(a[ny][nx]=='$') {     // 4. '$'
                    visited[ny][nx]=true;
                    q1.push({ny,nx});

                    cnt++;
                }
            }
        }
    }

    printf("%d\n",cnt);
}

int main() {

    cin>>tc;

    while(tc--) {
        memset(a,false,sizeof(a));
        memset(key,false,sizeof(key));
        memset(visited,false,sizeof(visited));
        cin>>n>>m;

        for(int i=0;i<n+2;i++) {
            for(int j=0;j<m+2;j++) {
                if(i==0 || i==n+1 || j==0 || j==m+1) a[i][j]='.';
                else scanf(" %1c",&a[i][j]);
            }
        }

        string s;
        cin>>s;

        if(s!="0") {
            for(int i=0;i<s.size();i++) {
                key[s.at(i)-'a']=true;
            }
        }

        bfs();
    }    

    return 0;
}