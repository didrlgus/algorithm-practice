// 되돌리기
#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<string,int>> v;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    while(n--) {
        string type;cin>>type;
        if(type=="type") {
            string a;int b;
            cin>>a>>b;
            if((int)v.size()==0) v.push_back({a,b});
            else v.push_back({v.back().first+a,b});
        } else {
            int a,b,diff,idx=0;
            cin>>a>>b;
            diff=b-a;
            for(auto it:v) {
                if(it.second>=diff) break;
                idx++;
            }
            if(idx==0) v.push_back({"",b});
            else v.push_back({v[idx-1].first,b});
        }
    }
    cout<<v.back().first<<'\n';
    return 0;
}