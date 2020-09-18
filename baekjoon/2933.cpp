// 미네랄
#include<bits/stdc++.h>
using namespace std;
int n,m,k,dy[]={0,0,1,-1},dx[]={1,-1,0,0};
char arr[105][105];
bool visited[105][105];
vector<int> v;
vector<pair<int,int>> vv,vvv;
void dfs(int y,int x) {
    visited[y][x]=true;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(!visited[ny][nx]&&arr[ny][nx]=='x') dfs(ny,nx);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++) {
        int a;scanf("%d",&a);
        v.push_back(a);
    }
    for(int i=0;i<(int)v.size();i++) {
        memset(visited,false,sizeof(visited));
        vv.clear();vvv.clear();
        int row=n-v[i];
        if(!(i&1)) {
            for(int j=0;j<m;j++) {
                if(arr[row][j]=='x') {
                    arr[row][j]='.';
                    break;
                }
            }
        } else {
            for(int j=m-1;j>=0;j--) {
                if(arr[row][j]=='x') {
                    arr[row][j]='.';
                    break;
                }
            }
        }
        for(int c=0;c<m;c++) {
            if(!visited[n-1][c]&&arr[n-1][c]=='x') dfs(n-1,c);
        }
        for(int r=0;r<n;r++) {
            for(int c=0;c<m;c++) {
                if(!visited[r][c]&&arr[r][c]=='x') {
                    vv.push_back({r,c});
                    arr[r][c]='.';
                }
            }
        }
        bool flag=false;
        if(!vv.empty()) {
            while(!flag) {
                for(auto it:vv) vvv.push_back({++it.first,it.second});
                for(auto it:vvv) {
                    if(it.first==n||arr[it.first][it.second]=='x') {
                        flag=true;
                        break;
                    }
                }
                if(!flag) vv=vvv;
                vvv.clear();
            }
            for(auto it:vv) arr[it.first][it.second]='x';
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) printf("%c",arr[i][j]);
        printf("\n");
    }
    return 0;
}