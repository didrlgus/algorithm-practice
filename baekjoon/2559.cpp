// 수열
#include<bits/stdc++.h>
using namespace std;
int n,k,arr[100005],val,ret;
int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<k;i++) val+=arr[i];
    ret=val;
    for(int i=k;i<n;i++) {
        val-=arr[i-k];
        val+=arr[i];
        ret=max(ret,val);
    }
    printf("%d\n",ret);
    return 0;
}