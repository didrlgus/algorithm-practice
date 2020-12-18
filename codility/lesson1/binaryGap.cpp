#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int ret=-1,len;
int solution(int N) {
    while(N>0) {
        v.push_back(N%2);
        N/=2;
    }
    for(int i=(int)v.size()-1;i>=0;i--) {
        if(v[i]==1) {
            ret=max(ret,len);
            len=0;
        } else len++;
    }
    return ret;
}
int main() {
    int n;scanf("%d",&n);
    printf("%d\n",solution(n));
    return 0;
}