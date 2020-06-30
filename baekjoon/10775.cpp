// 공항
#include<bits/stdc++.h>
using namespace std;
int n,m,ret;
vector<int> v1,v2;
int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) v1.push_back(i);
    for(int i=0;i<m;i++) {
        int a;scanf("%d",&a);
        v2.push_back(a);  
    }
    for(auto it:v2) {
        auto it2=upper_bound(v1.begin(),v1.end(),it);
        if(it2!=v1.begin()) {
            ret++;
            v1.erase(--it2);
        } else break;
    }
    printf("%d\n",ret);
    return 0;
}