// 선 긋기
#include<bits/stdc++.h>
using namespace std;
const int INF=-2e9;
int n,ret;
vector<pair<int,int>> v;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    int s=INF,e=INF;
    for(auto iter:v) {
        if(e<iter.first) {
            ret+=e-s;
            s=iter.first;
            e=iter.second;
        } else e=max(e,iter.second);
    }
    ret+=e-s;
    printf("%d\n",ret);
    return 0;
}