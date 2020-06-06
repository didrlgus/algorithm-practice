// 수열의 변화
#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
vector<int> v1;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    cin>>s;
    vector<string> stv=split(s,',');
    for(int i=0;i<(int)stv.size();i++) v1.push_back(atoi(stv[i].c_str()));
    while(k--) {
        vector<int> v2;
        for(int i=0;i<(int)v1.size()-1;i++) {
            v2.push_back(v1[i+1]-v1[i]);
        }
        v1=v2;
    }
    for(int i=0;i<(int)v1.size()-1;i++) printf("%d,",v1[i]);
    printf("%d",v1.back());
    return 0;
}