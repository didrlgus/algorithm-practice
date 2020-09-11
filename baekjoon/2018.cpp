// 수들의 합 5
#include<bits/stdc++.h>
using namespace std;
int n,lo,hi,sum,ret;
int main() {
    scanf("%d",&n);
    while(true) {
        if(sum>n) sum-=lo++;
        else if(hi==n) break;
        else sum+=++hi;
        if(sum==n) ret++;
    }
    printf("%d\n",ret);
    return 0;
}