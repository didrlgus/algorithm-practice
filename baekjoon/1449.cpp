// 수리공 항승
#include<bits/stdc++.h>
using namespace std;
int n,l,ret;
vector<int> v;
int main() {
    scanf("%d %d",&n,&l);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int e=v[0]+l;
    ret++;
    for(int i=1;i<n;i++) {
        if(e>v[i]) continue;
        e=v[i]+l;
        ret++;
    }
    printf("%d\n",ret);
    return 0;
}