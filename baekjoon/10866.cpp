// 덱
#include<bits/stdc++.h>
using namespace std;
int n;
deque<int> dq;
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
    while(n--) {
        string s;
        getline(cin,s);
        vector<string> v=split(s,' ');
        if((int)v.size()==2) {
            if(v[0]=="push_front") dq.push_front(stoi(v[1]));
            else dq.push_back(stoi(v[1]));
        } else {
            if(v[0]=="pop_front") {
                if(dq.empty()) cout<<-1<<'\n';
                else {
                    cout<<dq.front()<<'\n';
                    dq.pop_front();
                }
            } else if(v[0]=="pop_back") {
                if(dq.empty()) cout<<-1<<'\n';
                else {
                    cout<<dq.back()<<'\n';
                    dq.pop_back();
                }
            } else if(v[0]=="size") {
                cout<<(int)dq.size()<<'\n';
            } else if(v[0]=="empty") {
                if(dq.empty()) cout<<1<<'\n';
                else cout<<0<<'\n';
            } else if(v[0]=="front") {
                if(dq.empty()) cout<<-1<<'\n';
                else cout<<dq.front()<<'\n';
            } else {
                if(dq.empty()) cout<<-1<<'\n';
                else cout<<dq.back()<<'\n';
            }
        }
    }
    return 0;
}