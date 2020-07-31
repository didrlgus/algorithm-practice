// 회전 초밥
#include<bits/stdc++.h>
using namespace std;
const int INF=-987654321;
int n,d,k,c,arr[6000005],cnt,ret=INF,check[3005];
int main() {
    scanf("%d%d%d%d",&n,&d,&k,&c);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        arr[i+n]=arr[i];
        if(i<k) {
            if(!check[arr[i]]) cnt++;
            check[arr[i]]++;
        }
    }
    if(!check[c]) cnt++;
    check[c]++;
    for(int i=0;i<n-1;i++) {
        if(check[arr[i]]==1) cnt--;
        check[arr[i]]--;
        if(!check[arr[i+k]]) cnt++;
        check[arr[i+k]]++;
        ret=max(ret,cnt);
    }
    printf("%d\n",ret);
    return 0;
}