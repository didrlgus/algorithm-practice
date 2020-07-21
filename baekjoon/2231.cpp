// 분해합
#include<bits/stdc++.h>
using namespace std;
int n,a,ret;
int func(int x) {
    int sum=x;
    while(x>0) {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        if(func(i)==n) {
            ret=i;
            break;
        }
    }
    printf("%d\n",ret);
    return 0;
}