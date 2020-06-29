// Fly me to the Alpha Centauri
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tc;
int main() {
    scanf("%d",&tc);
    while(tc--) {
        ll x,y;
        scanf("%lld %lld",&x,&y);
        ll diff=y-x,idx=1;
        while(idx*idx<=diff) idx++;
        idx--;
        ll remain=(y-x)-(idx*idx);
        remain=(ll)ceil((double)remain/(double)idx);
        printf("%lld\n",idx*2-1+remain);
    }
    return 0;
}