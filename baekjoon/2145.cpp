// 숫자 놀이
#include<bits/stdc++.h>
using namespace std;
int n;
int func(int x) {
    int sum=0;
    while(x) {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main() {
    while(true) {
        scanf("%d",&n);
        if(n==0) break;
        int ret=n;
        while(ret/10) ret=func(ret);
        printf("%d\n",ret);
    }
    return 0;
}