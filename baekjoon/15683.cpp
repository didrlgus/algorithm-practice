// 감시
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> arr,tmp;
vector<pair<pair<int,int>,int>> v;          // cctv 좌표, 번호
vector<int> v2;                             // 방향 저장 좌표
int n,m;
int mn=987654321;

void right(vector<vector<int>>& tmp,int y,int x) {
    for(int j=x;j<m;j++) {
        if(tmp[y][j]==6) break;
        tmp[y][j]=-1;
    }
}

void down(vector<vector<int>>& tmp,int y,int x) {
    for(int i=y;i<n;i++) {
        if(tmp[i][x]==6) break;
        tmp[i][x]=-1;
    }
}

void left(vector<vector<int>>& tmp,int y,int x) {
    for(int j=x;j>=0;j--) {
        if(tmp[y][j]==6) break;
        tmp[y][j]=-1;
    }
}

void up(vector<vector<int>>& tmp,int y,int x) {
    for(int i=y;i>=0;i--) {
        if(tmp[i][x]==6) break;
        tmp[i][x]=-1;
    }
}

void dfs() {
    if(v2.size()==v.size()) {
        tmp=arr;

        for(int i=0;i<v.size();i++) {
            int y=v[i].first.first,x=v[i].first.second;
            int num=v[i].second;

            if(num==1) {
                if(v2[i]==0) {                  // >
                    right(tmp,y,x);
                } else if(v2[i]==1) {           // v
                    down(tmp,y,x);
                } else if(v2[i]==2) {           // <
                    left(tmp,y,x);
                } else if(v2[i]==3) {           // ^
                    up(tmp,y,x);
                }
            } else if(num==2) {
                if(v2[i]==0 || v2[i]==2) {
                    right(tmp,y,x);
                    left(tmp,y,x);
                } else {
                    up(tmp,y,x);
                    down(tmp,y,x);
                }
            } else if(num==3) {
                if(v2[i]==0) {
                    up(tmp,y,x);
                    right(tmp,y,x);
                } else if(v2[i]==1) {
                    right(tmp,y,x);
                    down(tmp,y,x);
                } else if(v2[i]==2) {
                    left(tmp,y,x);
                    down(tmp,y,x);
                } else if(v2[i]==3) {
                    left(tmp,y,x);
                    up(tmp,y,x);
                }
            } else if(num==4) {
                if(v2[i]==0) {
                    up(tmp,y,x);
                    right(tmp,y,x);
                    left(tmp,y,x);
                } else if(v2[i]==1) {
                    up(tmp,y,x);
                    right(tmp,y,x);
                    down(tmp,y,x);
                } else if(v2[i]==2) {
                    left(tmp,y,x);
                    right(tmp,y,x);
                    down(tmp,y,x);
                } else if(v2[i]==3) {
                    up(tmp,y,x);
                    left(tmp,y,x);
                    down(tmp,y,x);
                }
            } else {
                up(tmp,y,x);
                down(tmp,y,x);
                left(tmp,y,x);
                right(tmp,y,x);
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(tmp[i][j]==0) cnt++;
            }
        }
        mn=min(mn,cnt);

        return;
    }
    for(int i=0;i<4;i++) {      // 회전방향
        v2.push_back(i);
        dfs();
        v2.pop_back();
    }
}

int main() {
    scanf("%d %d",&n,&m);
    arr.resize(15,vector<int>(15,0));
    tmp.resize(15,vector<int>(15,0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]>=1 && arr[i][j]<=5) {
                v.push_back({{i,j},arr[i][j]});
                arr[i][j]=-1;
            }
        }
    }

    dfs();
    printf("%d\n",mn);
    return 0;
}