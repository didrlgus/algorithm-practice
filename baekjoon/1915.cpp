// 가장 큰 정사각형
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[1005][1005],ret;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%1d",&arr[i][j]);
    }
    for(int i=0;i<n;i++) if(arr[i][0]) ret=1;
    for(int j=1;j<m;j++) if(arr[0][j]) ret=1;
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(arr[i][j]) {
                arr[i][j]=min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]))+1;
                ret=max(ret,arr[i][j]);
            }
        }
    }
    printf("%d\n",ret*ret); 
    return 0;
}