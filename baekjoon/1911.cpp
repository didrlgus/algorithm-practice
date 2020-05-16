// 흙길 보수하기
#include<bits/stdc++.h>

using namespace std;

int n,k;
vector<pair<int,int>> v;
int main() {

    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        v.push_back({a,b});
    }

    sort(v.begin(),v.end());
    int cnt=0;
    int idx=0;
    for(int i=0;i<v.size();i++) {
        idx=idx>v[i].first?idx:v[i].first;

        int diff=v[i].second-idx;
        if(diff<=0) continue;
        
        int a=diff%k;
        int b=diff/k;
        cnt+=a>0?b+1:b;
        
        idx=a>0?v[i].second+k-a:v[i].second;
    }

    printf("%d\n",cnt);
    return 0;
}