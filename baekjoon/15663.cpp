// N과 M (9)
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v1,v2;
bool check[15];
set<vector<int>> st;
void permu(vector<int>& v2) {
    if((int)v2.size()==m) {
        vector<int> v;
        for(auto iter:v2) v.push_back(v1[iter]);
        st.insert(v);
        return;
    }
    for(int i=0;i<n;i++) {
        if(check[i]) continue;
        check[i]=true;
        v2.push_back(i);
        permu(v2);
        v2.pop_back();
        check[i]=false;
    }
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        v1.push_back(a);
    }
    sort(v1.begin(),v1.end());
    permu(v2);
    for(auto iter:st) {
        for(auto e:iter) printf("%d ",e);
        printf("\n");
    }
    return 0;
}