// 봄버맨
#include<bits/stdc++.h>
using namespace std;
int n,m,k,arr[205][205],dy[]={0,0,1,-1},dx[]={1,-1,0,0};
vector<pair<int,int>> v;
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char c;scanf(" %1c",&c);
            if(c=='.') arr[i][j]=-1;
            if(c=='O') arr[i][j]=1;
        }
    }
    k--;
    int turn=1;
    while(k--) {
        if(turn&1) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    if(arr[i][j]==-1) arr[i][j]=0;
                    else arr[i][j]++;
                }
            }
        } else {
            v.clear();
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    arr[i][j]++;
                    if(arr[i][j]==3) v.push_back({i,j});
                }
            }
            for(auto it:v) {
                int y=it.first,x=it.second;
                if(arr[y][x]!=-1) arr[y][x]=-1;
                for(int i=0;i<4;i++) {
                    int ny=y+dy[i],nx=x+dx[i];
                    if(ny<0||nx<0||ny>=n||nx>=m||arr[ny][nx]==-1) continue;
                    arr[ny][nx]=-1;
                }
            }
        }
        turn++;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]>=0) printf("O");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}