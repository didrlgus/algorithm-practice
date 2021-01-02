// 세로읽기
#include<bits/stdc++.h>
using namespace std;
int n=5;
vector<string> v;
int main() {
    while(n--) {
        string s;cin>>s;
        v.push_back(s);
    }
    for(int j=0;j<15;j++) {
        for(int i=0;i<5;i++) {
            if(j<(int)v[i].size()) cout<<v[i][j];
        }
    }
    cout<<'\n';
    return 0;
}