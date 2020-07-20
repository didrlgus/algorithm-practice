// 차이를 최소로
#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,t,lo,hi=INF,arr[100005],tmp[100005],ret[100005];
bool check(int diff) {
    int cnt=0;
    for(int i=0;i<n-1;i++) {
        if(tmp[i+1]-tmp[i]>diff) {
            int a=tmp[i+1]-tmp[i]-diff;
            cnt+=a;
            tmp[i+1]-=a;
        }
    }
    for(int i=n-1;i>=1;i--) {
        if(tmp[i-1]-tmp[i]>diff) {
            int a=tmp[i-1]-tmp[i]-diff;
            cnt+=a;
            tmp[i-1]-=a;
        }
    }
    if(cnt<=t) return true;
    return false;
}
int main() {
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int mid=0;
    while(lo<=hi) {
        memcpy(tmp,arr,sizeof(arr));
        mid=(lo+hi)/2;
        if(check(mid)) {
            for(int i=0;i<n;i++) ret[i]=tmp[i];
            hi=mid-1;
        } else lo=mid+1;
    }
    for(int i=0;i<n;i++) printf("%d ",ret[i]);
    return 0;
}