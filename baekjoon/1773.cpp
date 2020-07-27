// 폭죽쇼
#include<bits/stdc++.h>
using namespace std;
int n,m,ret;
bool arr[2000005];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        int a;scanf("%d",&a);
        for(int j=a;j<=m;j+=a) arr[j]=true;
    }
    for(int i=0;i<=m;i++) if(arr[i]) ret++;
    printf("%d\n",ret);
    return 0;
}