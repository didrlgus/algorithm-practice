// 두 배열의 합
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,arr_a[1005],arr_b[1005];
ll ret;
vector<ll> v1,v2;
int main() {
    scanf("%d%d",&t,&n);
    for(int i=0;i<n;i++) scanf("%d",&arr_a[i]);
    scanf("%d",&m);
    for(int i=0;i<m;i++) scanf("%d",&arr_b[i]);
    for(int i=0;i<n;i++) {
        ll sum=arr_a[i];
        v1.push_back(sum);
        for(int j=i+1;j<n;j++) {
            sum+=arr_a[j];
            v1.push_back(sum);
        }
    }
    for(int i=0;i<m;i++) {
        ll sum=arr_b[i];
        v2.push_back(sum);
        for(int j=i+1;j<m;j++) {
            sum+=arr_b[j];
            v2.push_back(sum);
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(auto it:v1) {
        ll diff=t-it;
        ret+=upper_bound(v2.begin(),v2.end(),diff)-lower_bound(v2.begin(),v2.end(),diff);
    }
    printf("%lld\n",ret);
    return 0;
}