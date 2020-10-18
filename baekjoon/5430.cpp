// AC
#include<bits/stdc++.h>
using namespace std;
int tc;
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
    cin>>tc;
    while(tc--) {
        deque<int> dq;
        string func;cin>>func;
        int n;cin>>n;
        string num;cin>>num;
        string valid_num=num.substr(1,num.length()-2);
        if(valid_num.length()>0) {
            vector<string> splt=split(valid_num,',');
            for(auto str:splt) {
                dq.push_back(atoi(str.c_str()));
            }
        }
        bool dir=true;
        bool flag=false;
        for(auto c:func) {
            if(c=='R') {
                dir=!dir;
            } else {
                if(dq.empty()) {
                    flag=true;
                    break;
                }
                if(dir) dq.pop_front();
                else dq.pop_back();
            }
        }
        if(flag) {
            cout<<"error"<<'\n';
            continue;
        }
        if(dq.empty()) {
            cout<<"[]"<<'\n';
            continue;
        }
        if(dir) {
            for(int i=0;i<(int)dq.size();i++) {
                if(i==0) cout<<'['<<dq[i];
                else cout<<','<<dq[i];
            }
            cout<<']';
        } else {
            for(int i=(int)dq.size()-1;i>=0;i--) {
                if(i==(int)dq.size()-1) cout<<'['<<dq[i];
                else cout<<','<<dq[i];
            }
            cout<<']';
        }
        cout<<'\n';
    }
    return 0;
}