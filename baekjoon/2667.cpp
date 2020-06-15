// 단지번호붙이기
#include<bits/stdc++.h>
using namespace std;
int n,cnt,dy[]={0,0,1,-1},dx[]={1,-1,0,0};
char arr[30][30];
bool visited[30][30];
vector<int> v;
int dfs(int y,int x) {
    visited[y][x]=true;
    int ret=0;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=n) continue;
        if(arr[ny][nx]=='1'&&!visited[ny][nx]) ret+=dfs(ny,nx)+1;
    }
    return ret;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf(" %1c",&arr[i][j]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j]=='1'&&!visited[i][j]) {
                v.push_back(dfs(i,j)+1);
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    sort(v.begin(),v.end());
    for(auto iter:v) printf("%d\n",iter);
    return 0;
}