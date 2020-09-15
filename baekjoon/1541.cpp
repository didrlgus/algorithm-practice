// 잃어버린 괄호
#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> ret;
int ans;
vector<string> split(string strToSplit, char delimeter) {
    stringstream ss(strToSplit);
    string item;
	vector<std::string> splittedStrings;
    while (getline(ss, item, delimeter)) {
		splittedStrings.push_back(item);
    }
	return splittedStrings;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>s;
    vector<string> v;
    v=split(s,'-');
    for(int i=1;i<(int)v.size();i++) {
        vector<string> vv=split(v[i],'+');
        int sum=0;
        for(auto it:vv) sum+=stoi(it.c_str());
        ret.push_back(sum);
    }
    if(v[0]!="") {
        vector<string> vvv=split(v[0],'+');
        for(auto it:vvv) ans+=stoi(it.c_str());
    }
    for(auto it:ret) ans-=it;
    cout<<ans<<'\n';
    return 0;
}