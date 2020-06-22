// 직사각형에서 탈출
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int y,x,n,m,ret=INF;
int main() {
    scanf("%d %d %d %d",&x,&y,&m,&n);
    ret=min(n-y,y-0);
    ret=min(ret,min(m-x,x-0));
    printf("%d\n",ret);
    return 0;
}