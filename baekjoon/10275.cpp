// 골드 러시
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tc;
ll n,a,b;
int main() {
    scanf("%d",&tc);
    while(tc--) {
        int ret=0;
        scanf("%lld %lld %lld",&n,&a,&b);
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        pq.push(pow(2,n));
        ll mn=min(a,b);
        while(mn>0) {
            if(pq.top()>mn) {
                ret++;
                ll tmp=pq.top();
                pq.pop();
                pq.push(tmp/2);
                pq.push(tmp/2);
            }
            else {
                mn-=pq.top();
                pq.pop();
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}