// 숫자의 합
#include<bits/stdc++.h>
using namespace std;
int n,ret;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        char c;
        scanf(" %1c",&c);
        ret+=c-'0';
    }
    printf("%d\n",ret);
    return 0;
}