// 가장 큰 금민수
#include<bits/stdc++.h>
using namespace std;
int n,ret;
bool check(int x) {
    string s=to_string(x);
    for(auto c:s) {
        if(c!='4'&&c!='7') return false;
    }
    return true;
}
int main() {
    scanf("%d",&n);
    for(int i=4;i<=n;i++) {
        if(check(i)) ret=i;
    }
    printf("%d\n",ret);
    return 0;
}