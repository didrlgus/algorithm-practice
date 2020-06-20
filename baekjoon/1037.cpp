// 약수
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    printf("%d\n",v.front()*v.back());
    return 0;
}