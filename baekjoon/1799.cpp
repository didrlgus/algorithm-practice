// 비숍
#include<bits/stdc++.h>
using namespace std;
int n,arr[15][15];
bool cross1[30],cross2[30];
int dfs(int row,bool toggle) {
    int ret=0;
    for(int i=row;i<n;i++) {
        int start=(i&1)?toggle:!toggle;
        for(int j=start;j<n;j+=2) {
            if(!arr[i][j]) continue;
            if(cross1[i+j]||cross2[i-j+n-1]) continue;
            cross1[i+j]=true;
            cross2[i-j+n-1]=true;
            ret=max(ret,dfs(i,toggle)+1);
            cross1[i+j]=false;
            cross2[i-j+n-1]=false;
        }
    }
    return ret;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
    }
    printf("%d\n",dfs(0,0)+dfs(0,1));
    return 0;
}