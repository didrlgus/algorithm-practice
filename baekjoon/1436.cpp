// 영화감독 숌
#include<bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<string> v;
    cin>>n;
    
    int start=666;
    while(true) {
        string s=to_string(start++);
        
        if(s.find("666")!=-1) v.push_back(s);

        if(v.size()>=n) break;
    }
    cout<<v[n-1]<<"\n";

    return 0;
}