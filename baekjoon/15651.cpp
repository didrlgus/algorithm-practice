// N과 M (3)
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
void combi() {
    if((int)v.size()==m) {
        for(auto it:v) printf("%d ",it);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++) {
        v.push_back(i);
        combi();
        v.pop_back();
    }
}
int main() {
    scanf("%d%d",&n,&m);
    combi();
    return 0;
}