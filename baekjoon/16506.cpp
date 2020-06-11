// CPU
#include<bits/stdc++.h>
using namespace std;
string arr[]={"ADD","ADDC","SUB","SUBC","MOV","MOVC","AND","ANDC","OR","ORC","NOT","MULT",
        "MULTC","LSFTL","LSFTLC","LSFTR","LSFTRC","ASFTR","ASFTRC","RL","RLC","RR","RRC"};
map<string,int> mp;
int n;
vector<string> split(string strToSplit, char delimeter) {
    stringstream ss(strToSplit);
    string item;
	vector<std::string> splittedStrings;
    while (getline(ss, item, delimeter)) {
		splittedStrings.push_back(item);
    }
	return splittedStrings;
}
string tobin(int x) {
    if(x==0) return "0";
    vector<int> v;
    while(x>0) {
        v.push_back(x%2);
        x/=2;
    }
    string s="";
    for(int i=(int)v.size()-1;i>=0;i--) s+=to_string(v[i]);
    return s;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    for(int i=0;i<23;i++) {
        if(i<=10) mp[arr[i]]=i;
        else mp[arr[i]]=i+1;
    }
    cin>>n;cin.ignore();
    for(int i=0;i<n;i++) {
        string s,ret="";
        getline(cin,s);
        vector<string> v=split(s,' ');
        string opStr=tobin(mp[v[0]]);
        for(int j=0;j<5-(int)opStr.size();j++) ret+="0";
        ret+=opStr;ret+="0";
        string rdStr=tobin(stoi(v[1]));
        for(int j=0;j<3-(int)rdStr.size();j++) ret+="0";
        ret+=rdStr;
        string raStr=tobin(stoi(v[2]));
        for(int j=0;j<3-(int)raStr.size();j++) ret+="0";
        ret+=raStr;
        if(ret[4]=='0') {
            string rbStr=tobin(stoi(v[3]));
            for(int j=0;j<3-(int)rbStr.size();j++) ret+="0";
            ret+=rbStr;
            ret+="0";
        } else {
            string cStr=tobin(stoi(v[3]));
            for(int j=0;j<4-(int)cStr.size();j++) ret+="0";
            ret+=cStr;
        }
        cout<<ret<<"\n";
    }
    return 0;
}