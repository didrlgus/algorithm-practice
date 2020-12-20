// N과 M (2)
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
void combi(int here) {
    if((int)v.size()==m) {
        for(auto it:v) printf("%d ",it);
        printf("\n");
        return;
    }
    for(int i=here+1;i<=n;i++) {
        v.push_back(i);
        combi(i);
        v.pop_back();
    }
}
int main() {
    scanf("%d%d",&n,&m);
    combi(0);
    return 0;
}