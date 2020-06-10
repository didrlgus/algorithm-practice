// 행렬
#include<bits/stdc++.h>
using namespace std;
int n,m,ret;
char a[55][55],b[55][55];
void go(int y,int x) {
    for(int i=y;i<y+3;i++) {
        for(int j=x;j<x+3;j++) a[i][j]=(a[i][j]=='0')?'1':'0';
    }
}
bool check() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) if(a[i][j]!=b[i][j]) return false;
    }
    return true;
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&a[i][j]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&b[i][j]);
    }
    for(int i=0;i<n-2;i++) {
        for(int j=0;j<m-2;j++) {
            if(a[i][j]!=b[i][j]) {
                go(i,j);
                ret++;
            }
        }
    }
    printf("%d\n",check()?ret:-1);
    return 0;
}