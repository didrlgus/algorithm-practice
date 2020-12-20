// 귀여운 라이언
#include<bits/stdc++.h>
using namespace std;
const int INF=2e9;
int n,k,arr[1000005],hi,lo,len,ret=INF;
int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    len=(arr[0]==1)?1:0;
    if(k==len) {
        printf("1\n");
        return 0;
    }
    while(hi<n) {
        if(len<k) {
            hi++;
            if(arr[hi]==1) len++;
        } else {
            ret=min(ret,hi-lo+1);
            if(arr[lo]==1) len--;
            lo++;
        }
    }
    printf("%d\n",ret==INF?-1:ret);
    return 0;
}