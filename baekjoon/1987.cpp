// 1987. 알파벳
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;

char a[25][25];
bool visited[25][25];
bool check[30];

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

int level=1;
vector<int> v;

void dfs(int y,int x) {
    visited[y][x]=true;
    check[a[y][x]-'A']=true;
    
    for(int i=0;i<4;i++) {
        int ny=y+dy[i];
        int nx=x+dx[i];

        if(ny<0 || nx<0 || ny>=n || nx>=m) continue;

        if(!visited[ny][nx] && !check[a[ny][nx]-'A']) {
            visited[ny][nx]=true;
            check[a[ny][nx]-'A']=true;
            level++;

            dfs(ny,nx);

            visited[ny][nx]=false;
            check[a[ny][nx]-'A']=false;
            level--;
        }
    }
    v.push_back(level);
}

int main() {

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cin >> a[i][j];
    }

    dfs(0,0);

    sort(v.begin(),v.end(),greater<int>());
    printf("%d\n",v[0]);

    return 0;
}