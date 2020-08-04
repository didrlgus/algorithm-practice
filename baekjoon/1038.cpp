// 감소하는 수
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> v;
void dfs(ll val) {
    ll a=val%10,b=val*10;
    for(ll i=0;i<a;i++) {
        v.push_back(b+i);
        dfs(b+i);
    }
}
int main() {
    scanf("%lld",&n);
    for(ll i=0;i<=9;i++) {
        v.push_back(i);
        dfs(i);
    }
    sort(v.begin(),v.end());
    if(n>=1023) printf("-1\n");     // 총 2^10-1 가지 경우가 있음 (감소하는 수는 0~9까지의 부분집합 개수와 동일)
    else printf("%lld\n",v[n]);
    return 0;
}