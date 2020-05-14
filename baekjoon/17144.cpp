// 미세먼지 안녕!
#include<bits/stdc++.h>

using namespace std;

int n,m,t;
int arr[55][55];

int dy[]={0,0,-1,1};
int dx[]={-1,1,0,0};

int upY,upX,downY,downX;

void bfs() {
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j]>0) {
                q.push({i,j});
            }
        }
    }
    
    int tmp[55][55]={0,};
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) tmp[i][j]=arr[i][j];
    }

    while(q.size()) {
        int y=q.front().first, x=q.front().second;
        q.pop();

        int cnt=0;
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];

            if(ny<1||nx<1||ny>=n+1||nx>=m+1) continue;
            if(arr[ny][nx]==-1) continue;
            cnt++;
            arr[ny][nx]+=(tmp[y][x]/5);
            
        }   
        arr[y][x]-=(tmp[y][x]/5)*cnt;
    }
}

int main() {

    scanf("%d %d %d",&n,&m,&t);
    
    int flag=false;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            scanf("%d",&arr[i][j]);
            
            if(!flag && arr[i][j]==-1) {
                upY=i; upX=j; flag=true;
            } else if(flag && arr[i][j]==-1){
                downY=i; downX=j;
            }
        }
    }
    
    while(t--) {
        bfs();
        // 위쪽 청정기
        // 오른쪽
        for(int i=m;i>=2;i--) {
            arr[upY][i+1]=arr[upY][i];
        }
        arr[upY][2]=0;

        // 위
        for(int i=1;i<upY;i++) {
            arr[i-1][m]=arr[i][m];
        }
        arr[upY-1][m]=arr[upY][m+1];
        arr[upY][m+1]=0;

        // 왼쪽
        for(int i=1;i<=m-1;i++) {
            arr[1][i-1]=arr[1][i];
        }
        arr[1][m-1]=arr[0][m];
        arr[0][m]=0;

        // 아래
        for(int i=upY-2;i>=2;i--) {
            arr[i+1][1]=arr[i][1];
        }
        arr[2][1]=arr[1][0];
        arr[1][0]=0;

        // 아래쪽 청정기
        // 오른쪽
        for(int i=m;i>=2;i--) {
            arr[downY][i+1]=arr[downY][i];
        }
        arr[downY][2]=0;

        // 아래쪽
        for(int i=n;i>downY;i--) {
            arr[i+1][m]=arr[i][m];
        }
        arr[downY+1][m]=arr[downY][m+1];
        arr[downY][m+1]=0;

        // 왼쪽
        for(int i=1;i<=m;i++) {
            arr[n][i-1]=arr[n][i];
        }
        arr[n][m-1]=arr[n+1][m];
        arr[n+1][m]=0;

        // 위
        for(int i=downY+2;i<=n-1;i++) {
            arr[i-1][1]=arr[i][1];
        }
        arr[n-1][1]=arr[n][0];
        arr[n][0]=0;
    }

    int sum=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j]>0) sum+=arr[i][j];
        }
    }

    printf("%d\n",sum);

    return 0;
}