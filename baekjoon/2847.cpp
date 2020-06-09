// 게임을 만든 동준이
#include<bits/stdc++.h>
using namespace std;
int n,arr[105],ret;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=n-1;i>=1;i--) {
        if(arr[i]<=arr[i-1]) {
            ret+=arr[i-1]-(arr[i]-1);
            arr[i-1]=arr[i]-1;
        }
    }
    printf("%d\n",ret);
    return 0;
}