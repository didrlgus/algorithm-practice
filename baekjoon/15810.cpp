// 풍선 공장
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,arr[1000005],lo=1,hi=1e12,ret;
bool check(ll mid) {
    ll cnt=0;
    for(int i=0;i<n;i++) cnt+=mid/arr[i];
    return cnt>=m;
}
int main() {
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    while(lo<=hi) {
        ll mid=(lo+hi)/2;
        if(check(mid)) {
            hi=mid-1;
            ret=mid;
        }
        else lo=mid+1;
    }
    printf("%lld\n",ret);
    return 0;
}