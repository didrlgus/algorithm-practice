// 플러그
#include<bits/stdc++.h>
using namespace std;
int n,cnt,ret;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a;scanf("%d",&a);
        cnt+=a;
    }
    ret=cnt-(n-1);
    printf("%d\n",ret);
    return 0;
}