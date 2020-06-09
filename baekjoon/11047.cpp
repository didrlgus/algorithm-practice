// 동전 0
#include<bits/stdc++.h>
using namespace std;
int n,k,ret;
vector<int> v;
int main() {
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        int money;
        scanf("%d",&money);
        v.push_back(money);
    }
    for(int i=n-1;i>=0;i--) {
        if(v[i]>k) continue;
        ret+=k/v[i];
        k%=v[i];
    }
    printf("%d\n",ret);
    return 0;
}