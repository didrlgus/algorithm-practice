// 부분합
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,s,arr[100005],lo,hi,sum,ret=INF;
int main() {
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    while(true) {
        if(sum>=s) {
            ret=min(ret,hi-lo);
            sum-=arr[lo++];
        }
        else if(hi==n) break;
        else sum+=arr[hi++];
    }
    printf("%d\n",ret==INF?0:ret);
    return 0;
}