// 용돈 관리
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[100005],lo,hi=100005,ret;
bool check(int mid) {
    int cnt=0,money=0;
    for(int i=0;i<n;i++) {
        if(money<arr[i]) {
            if(mid<arr[i]) return false;
            money=mid-arr[i];
            cnt++;
        } else money-=arr[i];   
    }
    return cnt<=m;
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        lo=min(lo,arr[i]);
    }
    while(lo<=hi) {
        int mid=(lo+hi)/2;
        if(check(mid)) {
            hi=mid-1;
            ret=mid;
        } else lo=mid+1;
    }
    printf("%d\n",ret);
    return 0;
}