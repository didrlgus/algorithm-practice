// 용액 합성하기
#include<bits/stdc++.h>
using namespace std;
const int INF=2e9;
int n,lo,hi,ret=INF,ans=INF;
vector<int> v;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a;scanf("%d",&a);
        v.push_back(a);
    }
    hi=n-1;
    while(lo<hi) {
        int sum=v[lo]+v[hi];
        if(abs(sum)<ret) {
            ret=abs(sum);
            ans=sum;
        }
        if(sum<0) lo++;
        else hi--;
    }
    printf("%d\n",ans);
    return 0;
}