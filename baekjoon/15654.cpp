// N과 M (5)
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v,v2;
bool check[10005];
void permu() {
    if((int)v2.size()==m) {
        for(auto it:v2) printf("%d ",v[it]);
        printf("\n");
        return;
    }
    for(int i=0;i<n;i++) {
        if(check[i]) continue;
        check[i]=true;
        v2.push_back(i);
        permu();
        check[i]=false;
        v2.pop_back();
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        int a;scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    permu();
    return 0;
}