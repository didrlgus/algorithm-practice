// 보물
#include<bits/stdc++.h>
using namespace std;
int n,ret;
vector<int> v1,v2;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        v1.push_back(a);
    }
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        v2.push_back(a);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),greater<int>());
    for(int i=0;i<n;i++) ret+=(v1[i]*v2[i]);
    printf("%d\n",ret);
    return 0;
}