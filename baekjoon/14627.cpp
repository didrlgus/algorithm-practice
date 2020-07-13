// 파닭파닭
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s,c,lo=1,hi,arr[1000005],sum,ret;
bool check(ll mid) {
    ll cnt=0;
    for(ll i=0;i<s;i++) cnt+=arr[i]/mid;
    return cnt>=c;
}
int main() {
    scanf("%lld %lld",&s,&c);
    for(ll i=0;i<s;i++) {
        scanf("%lld",&arr[i]);
        hi=max(hi,arr[i]);
        sum+=arr[i];
    }
    while(lo<=hi) {
        ll mid=(lo+hi)/2;
        if(check(mid)) {
            lo=mid+1;
            ret=mid;
        } else hi=mid-1;
    }
    printf("%lld\n",sum-ret*c);
    return 0;
}