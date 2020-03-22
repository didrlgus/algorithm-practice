// 테트로미노
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int a[505][505];
bool visited[505][505];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n,m,max_=0;

int dfs(int x, int y, int cnt) {
    if(cnt>=5) {
        return 0;
    }

    int ans=0;

    for(int i=0;i<4;i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0 && nx<n && ny>=0 && ny<m) {
            if(!visited[nx][ny]) {
                visited[nx][ny]=true;
                ans = max(ans, dfs(nx,ny,cnt+1)+a[nx][ny]);
                visited[nx][ny]=false;
            }
        }
    }

    return ans;
}

int extra(int x, int y) {
    int ans=0;

    // ㅗ모양
    if(x>=1 && y>=1 && y<m-1)
        ans = max(ans, a[x][y]+a[x-1][y]+a[x][y-1]+a[x][y+1]);
    // ㅜ모양
    if(x<n-1 && y>=1 && y<m-1)
        ans = max(ans, a[x][y]+a[x+1][y]+a[x][y-1]+a[x][y+1]);
    // ㅏ모양
    if(x<n-1 && x>=1 && y<m-1)
        ans = max(ans, a[x][y]+a[x+1][y]+a[x-1][y]+a[x][y+1]);
    // ㅓ모양
    if(x<n-1 && x>=1 && y>=1)
        ans = max(ans, a[x][y]+a[x+1][y]+a[x-1][y]+a[x][y-1]);
    
    return ans;
}

int main() {

    scanf("%d %d", &n,&m);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            visited[i][j]=true;
            max_=max(max_, dfs(i, j, 1));
            max_=max(max_,extra(i,j));
            visited[i][j]=false;
        }
    }

    printf("%d\n", max_);

    return 0;
}