// 귀여운 라이언
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,k,lo,hi,lion_cnt,ret=INF;
bool arr[1000005];
int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) {
        int a;scanf("%d",&a);
        if(a==2) arr[i]=true;
    }
    while(true) {
        if(lion_cnt>=k) {
            if(!arr[lo]) lion_cnt--;
            lo++;
        } else if(hi==n) break;
        else {
            if(!arr[hi]) lion_cnt++;
            hi++;
        }
        if(lion_cnt==k) ret=min(ret,hi-lo);
    }
    printf("%d\n",ret==INF?-1:ret);
    return 0;
}