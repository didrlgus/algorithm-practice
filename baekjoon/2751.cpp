// 수 정렬하기 2
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int val;scanf("%d",&val);
        v.push_back(val);
    }
    sort(v.begin(),v.end());
    for(auto it:v) printf("%d\n",it);
    return 0;
}