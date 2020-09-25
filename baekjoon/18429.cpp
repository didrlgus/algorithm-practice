// 근손실
#include<bits/stdc++.h>
using namespace std;
int n,k,ret;
vector<int> v,v2;
bool check[10];
void permu() {
    if((int)v2.size()>=n) {
        int weight=500;
        bool flag=false;
        for(auto it:v2) {
            weight-=k;
            weight+=v[it];
            if(weight<500) {
                flag=true;
                break;
            }
        }
        if(!flag) ret++;
        return;
    }
    for(int i=0;i<v.size();i++) {
        if(!check[i]) {
            check[i]=true;
            v2.push_back(i);
            permu();
            check[i]=false;
            v2.pop_back();
        }
    }
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) {
        int a;scanf("%d",&a);
        v.push_back(a);
    }
    permu();
    printf("%d\n",ret);
    return 0;
}