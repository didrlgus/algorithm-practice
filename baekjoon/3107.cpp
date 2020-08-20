// IPv6
#include<bits/stdc++.h>
using namespace std;
int cnt;
string s,tmp;
vector<string> v,vv;
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
    v=split(s,':');
    for(auto i=v.begin();i<v.end();i++) {
        if(*i!="") cnt++;
    }
    tmp+=':';
    for(int i=0;i<8-cnt;i++) tmp+="0000:";
    auto double_colon = s.find("::",0,2);
    if(double_colon!=string::npos) s.replace(double_colon,2,tmp);
    if(s[0]==':') s=s.substr(1);
    vv=split(s,':');
    for(auto i=vv.begin();i<vv.end();i++) {
        string str=*i;
        while((int)str.size()<4) str='0'+str;
        *i=str;
    }
    cout<<vv[0];
    for(int i=1;i<(int)vv.size();i++) cout<<':'<<vv[i];
    return 0;
}