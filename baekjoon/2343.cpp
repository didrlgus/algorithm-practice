// 기타 레슨
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[100005],sum,lo=1,hi,ret;
bool check(int mid) {
    int cnt=1,p_sum=0;
    for(int i=0;i<n;i++) {
        if(p_sum+arr[i]>mid) {
            if(arr[i]>mid) return false;
            cnt++;
            p_sum=arr[i];
        } else p_sum+=arr[i];
    }
    return cnt<=m;
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    lo=arr[0];hi=sum;
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