// 뒤집힌 덧셈
#include<bits/stdc++.h>
using namespace std;
int n,m;
int rev(int x) {
    vector<int> v;
    int ret=0;
    while(x>0) {
        v.push_back(x%10);
        x/=10;
    }
    for(int i=0;i<(int)v.size();i++) ret+=(v[i]*pow(10,(int)v.size()-1-i));
    return ret;
}
int main() {
    scanf("%d %d",&n,&m);
    printf("%d\n",rev(rev(n)+rev(m)));
    return 0;
}