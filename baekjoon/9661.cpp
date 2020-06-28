// 돌 게임 7
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main() {
    scanf("%lld",&n);
    if(n%5==0||n%5==2) printf("CY");
    else printf("SK");
    return 0;
}