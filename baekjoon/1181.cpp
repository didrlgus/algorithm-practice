// 단어 정렬
#include<bits/stdc++.h>

using namespace std;

int n;
set<string> st;
vector<string> v;

bool cmp(string s1, string s2) {
    if(s1.size()==s2.size()) return s1<s2;
    return s1.size()<s2.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    while(n--) {
        string s;
        cin>>s;
        st.insert(s);
    }

    for(auto iter:st) v.push_back(iter);
    
    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<v.size();i++) cout<<v[i]<<"\n";

    return 0;
}