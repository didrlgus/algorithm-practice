// 가장 긴 증가하는 부분 수열 2
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main() {
    scanf("%d",&n);
    v.push_back(0);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        if(v.back()<a) v.push_back(a);
        else {
            int pos=lower_bound(v.begin(),v.end(),a)-v.begin();
            v[pos]=a;
        }
    }
    printf("%d\n",(int)v.size()-1);
    return 0;
}