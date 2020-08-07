// 두 용액
#include<bits/stdc++.h>
using namespace std;
const int INF=2e9;
int n,arr[100005],lo,hi,ret_lo,ret_hi,ret=INF;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+n);
    lo=0,hi=n-1;
    while(lo<hi) {
        int sum=arr[lo]+arr[hi];
        if(abs(sum)<ret) {
            ret=abs(sum);
            ret_lo=lo;
            ret_hi=hi;
        }
        if(sum<0) lo++;
        else hi--;
    }
    printf("%d %d\n",arr[ret_lo],arr[ret_hi]);
    return 0;
}