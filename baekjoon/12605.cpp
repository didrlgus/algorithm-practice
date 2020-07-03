// 단어순서 뒤집기
#include<bits/stdc++.h>
using namespace std;
int n;
string s;
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
    cin>>n;cin.ignore();
    int idx=1;
    while(n--) {
        getline(cin,s);
        vector<string> v=split(s,' ');
        string s1="Case #"+to_string(idx++)+": ",s2;
        for(int i=(int)v.size()-1;i>=0;i--) s2+=v[i]+' ';
        cout<<s1+s2<<'\n';
    }
    return 0;
}