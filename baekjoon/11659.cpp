// 구간 합 구하기 4
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[100005],sum[100005];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i];
    while(m--) {
        int s,e;
        scanf("%d %d",&s,&e);
        printf("%d\n",sum[e]-sum[s-1]);   
    }
    return 0;
}