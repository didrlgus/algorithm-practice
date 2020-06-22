// 이상한 곱셈
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
ll ret;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>a>>b;
    for(int i=0;i<(int)a.size();i++) {
        for(int j=0;j<(int)b.size();j++) ret+=(a[i]-'0')*(b[j]-'0')*1LL;
    }
    printf("%lld\n",ret);
    return 0;
}