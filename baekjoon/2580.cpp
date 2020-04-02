// 2580. 스도쿠
#include<cstdio>
#include<iostream>

using namespace std;

int a[15][15];

bool row[15][15];
bool col[15][15];
bool squre[15][15];

bool flag=false;

int toSqureIdx(int y,int x) {
    return (y/3)*3+(x/3);
}

void dfs(int current) {
    if(flag) return;

    if(current>=81) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) printf("%d ",a[i][j]);
            printf("\n");
        }
        flag=true;
    } else {
        int y=current/9;
        int x=current%9;

        if(a[y][x]) dfs(current+1);
        else {
            for(int i=1;i<=9;i++) {
                if(!row[y][i] && !col[x][i] && !squre[toSqureIdx(y,x)][i]) {
                    row[y][i]=true;
                    col[x][i]=true;
                    squre[toSqureIdx(y,x)][i]=true;
                    a[y][x]=i;

                    dfs(current+1);

                    row[y][i]=false;
                    col[x][i]=false;
                    squre[toSqureIdx(y,x)][i]=false;
                    a[y][x]=0;
                }
            }
        }
    }
}

int main() {

    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cin >> a[i][j];

            if(a[i][j]) {
                row[i][a[i][j]]=true;
                col[j][a[i][j]]=true;
                squre[toSqureIdx(i,j)][a[i][j]]=true;
            }
        }
    }

    dfs(0);

    return 0;
}