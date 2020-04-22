// [3차] 방금그곡
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string strToSplit, char delimeter) {
    stringstream ss(strToSplit);
    string item;
	vector<std::string> splittedStrings;
    while (getline(ss, item, delimeter)) {
		splittedStrings.push_back(item);
    }
	return splittedStrings;
}

bool cmp(pair<int,string> p1, pair<int,string> p2) {
    return p1.first>p2.first;   // 내림차순
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";

    vector<pair<int,string>> rv;

    for(int i=0;i<musicinfos.size();i++) {
        string s=musicinfos[i];

        vector<string> v=split(s,',');

        string start=v[0],end=v[1],name=v[2],info=v[3];

        vector<string> sv=split(start,':');
        vector<string> ev=split(end,':');

        string shs=sv[0],ehs=ev[0],sms=sv[1],ems=ev[1];

        int sh=atoi(shs.c_str()),eh=atoi(ehs.c_str()),sm=atoi(sms.c_str()),em=atoi(ems.c_str());

        int diff=(eh-sh)*60 + (em-sm);
        
        vector<string> iv;
        for(int j=0;j<info.size();j++) {
            if(j!=info.size()-1 && info[j]!='#' && info[j+1]=='#') {
                string a;
                a+=info[j]+32;          // 소문자로 변경 (중요 아이디어)
                iv.push_back(a);
                j++;
            } else {
                string a;
                a+=info[j];
                iv.push_back(a);
            }
        }

        string ns;
        int idx=0;
        while(ns.size()<diff) {
            ns+=iv[idx++];
            
            if(idx>=iv.size()) idx=0;
        }

        string nm;
        nm+=m[0];
        // CC#BCC#BCC#BCC#B
        for(int j=1;j<m.size();j++) {
            if(m[j]=='#') {
                nm[nm.size()-1]=nm[nm.size()-1]+32;     // 소문자로 변경
            } else nm+=m[j];
        }

        // ns   cDEFGABc
        // m    ABC
        //            6789
        if(ns.find(nm)!=string::npos) {     // 해당 문자열을 포함한다면
            rv.push_back({diff,name});
        }
    }

    sort(rv.begin(),rv.end(),cmp);

    if(rv.size()==0) answer="(None)";
    else answer=rv.front().second;

    return answer;
}

int main() {

    string m="CC#BCC#BCC#BCC#B";
    vector<string> musicinfos={"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};

    string result=solution(m,musicinfos);
    cout<<result<<endl;

    return 0;
}