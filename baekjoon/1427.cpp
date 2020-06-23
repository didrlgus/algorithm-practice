// 소트인사이드
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main() {
    scanf("%d",&n);
    while(n>0) {
        v.push_back(n%10);
        n/=10;
    }
    sort(v.begin(),v.end(),greater<>());
    for(auto it:v) printf("%d",it);
    return 0;
}