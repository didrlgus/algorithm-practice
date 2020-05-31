// 0의 개수
#include<bits/stdc++.h>
using namespace std;
int tc;
int counting(int a) {
    int cnt=0;
    if(a==0) return 1;
    while(a>0) {
        if(a%10==0) cnt++;
        a/=10;
    }
    return cnt;
}
int main() {
    scanf("%d",&tc);
    while(tc--) {
        int n,m;
        scanf("%d %d",&n,&m);
        int cnt=0;
        for(int i=n;i<=m;i++) {
            cnt+=counting(i);
        }
        printf("%d\n",cnt);
    }
    return 0;
}