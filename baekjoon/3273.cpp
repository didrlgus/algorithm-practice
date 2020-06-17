// 두 수의 합
#include<bits/stdc++.h>
using namespace std;
int n,x,ret;
int main() {
    scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i]);
    scanf("%d",&x);
    sort(v.begin(),v.end());
    int s=0,e=n-1;
    while(s<e) {
        int sum=v[s]+v[e];
        if(sum==x) e--,ret++;
        else if(sum>x) e--;
        else s++;
    }
    printf("%d\n",ret);
    return 0;
}