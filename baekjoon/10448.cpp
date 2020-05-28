// 유레카 이론
#include<bits/stdc++.h>
using namespace std;

int tc,arr[200],val=2,n;
vector<int> v;
bool flag;
void combi(vector<int>& vv) {
    if(flag==true) return;
    if((int)vv.size()==3) {
        int sum=0;
        for(auto it:vv) sum+=v[it];
        if(sum==n) {
            printf("1\n");
            flag=true;
        }
        return;
    }
    for(int i=0;i<(int)v.size();i++) {
        vv.push_back(i);
        combi(vv);
        vv.pop_back();
    }
    return;
}
int main() {
    scanf("%d",&tc);
    v.push_back(1);
    while(true) {
        v.push_back(v.back()+val++);
        if(v.back()>1000) break;
    }
    v.pop_back();
    while(tc--) {
        scanf("%d",&n);
        flag=false;
        vector<int> vv;
        combi(vv);
        if(!flag) printf("0\n");
    }
    return 0;
}