// 평균
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<double> v2;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    double mx=v.back();
    for(auto it:v) v2.push_back(it/mx*100);
    double sum=0;
    for(auto it:v2) sum+=it;
    printf("%0.2lf",sum/(int)v2.size());
    return 0;
}