// 2003. 수들의 합2
#include<bits/stdc++.h>
using namespace std;
int n,m,l,h,sum,ret;
int main() {
    scanf("%d %d",&n,&m);
    vector<int> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i]);
    while(true) {
        if(sum>=m) sum-=v[l++];
        else if(h==n) break;
        else sum+=v[h++];
        if(sum==m) ret++;
    }
    printf("%d\n",ret);
    return 0;
}
