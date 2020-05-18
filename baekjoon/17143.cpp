// 낚시왕
#include<bits/stdc++.h>

using namespace std;

struct shark {
    int s,d,z;
};

shark arr[105][105];
shark tmp[105][105];

int dy[]={-1,1,0,0};
int dx[]={0,0,1,-1};
int n,m,k;

int main() {
    scanf("%d %d %d",&n,&m,&k);

    for(int i=0;i<k;i++) {
        int y,x,s,d,z;
        scanf("%d %d %d %d %d",&y,&x,&s,&d,&z);
        y--;x--;d--;

        arr[y][x]={s,d,z};
    }

    int ret=0;
    for(int t=0;t<m;t++) {
        for(int i=0;i<n;i++) {
            if(arr[i][t].z>0) {
                ret+=arr[i][t].z;
                arr[i][t].z=0;                              // 낚시꾼에게 잡힘
                break;
            }
        }

        memcpy(tmp,arr,sizeof(arr));                        // 백업
        memset(arr,0,sizeof(arr));

        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                shark cur = tmp[i][j];

                if(cur.z>0) {
                    int ny=i+cur.s*dy[cur.d],nx=j+cur.s*dx[cur.d];

                    if(ny<0) {                              // 위쪽방향일 경우
                        ny*=-1;                             
                        cur.d=1;                            // 방향만 변경
                    }
                    if(ny>=n) {
                        int a=ny/(n-1), b=ny%(n-1);
                        if(a&1) {                           // 홀수
                            ny=n-1-b;
                            cur.d=0;
                        } else {
                            ny=b;
                        }
                    }

                    if(nx<0) {                              // 왼쪽방향일 경우
                        nx*=-1;
                        cur.d=2;
                    }
                    if(nx>=m) {
                        int a=nx/(m-1), b=nx%(m-1);
                        if(a&1) {
                            nx=m-1-b;
                            cur.d=3;
                        } else {
                            nx=b;
                        }
                    }

                    if(arr[ny][nx].z<cur.z) {
                        arr[ny][nx]={cur.s,cur.d,cur.z};
                    }
                }
            }
        }
    }

    printf("%d\n",ret);

    return 0;
}