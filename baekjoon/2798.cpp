// 블랙잭
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[105],ret=-1;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            for(int k=j+1;k<n;k++) {
                int sum=arr[i]+arr[j]+arr[k];
                if(sum>m) continue;
                ret=max(sum,ret);
            }
        }
    }
    printf("%d\n",ret);
    return 0;
}