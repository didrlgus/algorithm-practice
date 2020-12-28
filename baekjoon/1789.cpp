// 수들의 합
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s,sum;
int main() {
    scanf("%lld",&s);
    ll end=1;
    sum+=end;
    while(sum<=s) {    
        end++;
        sum+=end;
    }
    printf("%lld\n",end-1);
    return 0;
}