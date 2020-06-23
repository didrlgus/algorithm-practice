// List of Unique Numbers
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,arr[100005],cnt[100005],s,e;
ll ret;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    while(e<n) {
        if(cnt[arr[e]]) {
            ret+=(e-s);
            cnt[arr[s++]]--;
        } else cnt[arr[e++]]++;
    }
    ret+=1LL*(e-s)*(e-s+1)/2;
    printf("%lld\n",ret);
    return 0;
}