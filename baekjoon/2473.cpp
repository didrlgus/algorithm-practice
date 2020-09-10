// 세 용액
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e10;
int n,first,lo,hi,second,third;
ll arr[5010],ret=INF;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    sort(arr,arr+n);
    for(int i=0;i<n;i++) {
        lo=i+1,hi=n-1;  
        while(lo<hi) {
            ll sum=arr[i]+arr[lo]+arr[hi];
            if(abs(sum)<ret) {
                ret=abs(sum);
                first=i;
                second=lo;
                third=hi;
            }
            if(sum<0) lo++;
            else hi--;
        }
    }
    printf("%lld %lld %lld\n",arr[first],arr[second],arr[third]);
    return 0;
}