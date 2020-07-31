// 수 고르기
#include<bits/stdc++.h>
using namespace std;
const int INF=2e9;
int n,m,arr[100005],hi,lo,ret=INF;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+n);
    while(true) {
        int diff=arr[hi]-arr[lo];
        if(diff>=m) {
            ret=min(ret,diff);
            lo++;
        } 
        else if(hi==n-1) break;
        else hi++;
    }
    printf("%d\n",ret);
    return 0;
}