#include<bits/stdc++.h>
using namespace std;
int ret=-1;
vector<string> split(string strToSplit, char delimeter) {
    stringstream ss(strToSplit);
    string item;
	vector<std::string> splittedStrings;
    while (getline(ss, item, delimeter)) {
		splittedStrings.push_back(item);
    }
	return splittedStrings;
}
int solution(string &S) {
    vector<string> segment=split(S,' ');
    for(auto str:segment) {
        int digit_cnt=0,letter_cnt=0;
        bool flag=false;
        for(int i=0;i<(int)str.size();i++) { 
            if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')) letter_cnt++;
            else if(str[i]>='0'&&str[i]<='9') digit_cnt++;
            else {
                flag=true;
                break;
            }
        }
        if(flag) continue;
        if((letter_cnt%2==0)&&(digit_cnt&1)) ret=max(ret,(int)str.size());
    }
    return ret;
}