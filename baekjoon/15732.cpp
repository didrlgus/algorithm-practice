// 도토리 숨기기
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
struct p {
    ll s,e,interval;
};
ll n,k,d,hi=-INF,lo=INF,ret;
p arr[10005];
bool check(ll mid) {
    ll cnt=0;
    for(ll i=0;i<k;i++) {
        if(min(mid,arr[i].e)>=arr[i].s) cnt+=(min(mid,arr[i].e)-arr[i].s)/arr[i].interval+1;
    }
    return d<=cnt;
}
int main() {
    scanf("%lld %lld %lld",&n,&k,&d);
    for(ll i=0;i<k;i++) {
        ll s,e,interval;
        scanf("%lld %lld %lld",&s,&e,&interval);
        arr[i].s=s;arr[i].e=e;arr[i].interval=interval;
        lo=min(lo,arr[i].s);
        hi=max(hi,arr[i].e);
    }
    while(lo<=hi) {
        ll mid=(lo+hi)/2;
        if(check(mid)) {
            hi=mid-1;
            ret=mid;
        } else lo=mid+1;
    }
    printf("%lld\n",ret);
    return 0;
}