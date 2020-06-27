// 소가 길을 건너간 이유 1
#include<bits/stdc++.h>
using namespace std;
int n,ret,arr[15];
int main() {
    scanf("%d",&n);
    memset(arr,-1,sizeof(arr));
    for(int i=0;i<n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        if(arr[a]==-1) arr[a]=b;
        else if(arr[a]!=b) {
            ret++;
            arr[a]=b;
        }
    }
    printf("%d\n",ret);
    return 0;
}