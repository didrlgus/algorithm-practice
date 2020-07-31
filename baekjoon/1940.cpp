// ??
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[15005],lo,hi,ret;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+n);
    lo=0,hi=n-1;
    while(lo<hi) {
        if(arr[lo]+arr[hi]==m) ret++,lo++;
        else if(arr[lo]+arr[hi]<m) lo++;
        else hi--; 
    }
    printf("%d\n",ret);
    return 0;
}