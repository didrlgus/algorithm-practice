// 개똥벌레
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,h,ret=INF,ret_cnt;
vector<int> v1,v2;
int main() {
    scanf("%d%d",&n,&h);
    for(int i=0;i<n/2;i++) {
        int a,b;scanf("%d%d",&a,&b);
        v1.push_back(a);
        v2.push_back(b);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(int i=1;i<=h;i++) {
        int cnt1=0,cnt2=0;
        cnt1=v1.end()-lower_bound(v1.begin(),v1.end(),i);
        cnt2=v2.end()-upper_bound(v2.begin(),v2.end(),h-i);
        if(ret==cnt1+cnt2) ret_cnt++;
        else if(ret>cnt1+cnt2) {
            ret=cnt1+cnt2;
            ret_cnt=1;
        }
    }
    printf("%d %d\n",ret,ret_cnt);
    return 0;
}