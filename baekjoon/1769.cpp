// 3의 배수
#include<bits/stdc++.h>
using namespace std;
string s;
int sum,ret;
int func(int x) {
    int sum=0;
    while(x>0) {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>s;
    for(auto ch:s) sum+=ch-'0';
    if(sum>=10) {
        ret++;
        while(sum>=10) {
            sum=func(sum);
            ret++;
        }
    }
    printf("%d\n",ret);
    if(sum%3==0) printf("YES\n");
    else printf("NO\n");
    return 0;
}