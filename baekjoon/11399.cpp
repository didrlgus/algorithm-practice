// ATM
#include<bits/stdc++.h>
using namespace std;
int n,ret;
vector<int> v,v2;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a;scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    v2.push_back(v[0]);
    for(int i=1;i<(int)v.size();i++) v2.push_back(v2[i-1]+v[i]);
    for(auto it:v2) ret+=it;
    printf("%d\n",ret);
    return 0;
}