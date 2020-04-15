// 튜플
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <stdlib.h>

using namespace std;
/* STL, 문자열 split 연습하기 좋은 예제 */
struct p {
    int s;
    vector<string> v;
};

bool cmp(p a, p b) {
    return a.s<b.s;
}

vector<string> split(string strToSplit, char delimeter) {
    stringstream ss(strToSplit);
    string item;
	vector<std::string> splittedStrings;
    while (getline(ss, item, delimeter)) {
		splittedStrings.push_back(item);
    }
	return splittedStrings;
}

vector<string> split(string stringToBeSplitted,string delimeter)
{
	vector<string> splittedString;
	int startIndex = 0;
	int  endIndex = 0;
	while((endIndex = stringToBeSplitted.find(delimeter, startIndex)) < stringToBeSplitted.size()){
        string val = stringToBeSplitted.substr(startIndex, endIndex - startIndex);
		splittedString.push_back(val);
		startIndex = endIndex + delimeter.size();
 
	}
	if(startIndex < stringToBeSplitted.size()) {
		string val = stringToBeSplitted.substr(startIndex);
		splittedString.push_back(val);
	}
	return splittedString;
}

vector<int> solution(string s) {
    vector<int> answer;

    // s    {{2},{2,1},{2,1,3},{2,1,3,4}}
    vector<string> v=split(s.substr(1,s.size()-3),"},");

    vector<p> v2;

    // v    {2   {2,1    {2,1,3  {2,1,3,4
    for(int i=0;i<v.size();i++) {
        string ns=v[i];
        ns=ns.substr(1);

        // 2  2,1   2,1,3   2,1,3,4
        vector<string> tmp=split(ns,',');
        int size=tmp.size();

        v2.push_back({size,tmp});
    }

    sort(v2.begin(),v2.end(),cmp);

    set<string> set;

    for(int i=0;i<v2.size();i++) {
        vector<string> tmp=v2[i].v;

        for(int i=0;i<tmp.size();i++) {
            if (set.find(tmp[i])==set.end()) {      // set에 find로 찾은 요소가 없는 경우 true
                set.insert(tmp[i]);
                answer.push_back(atoi(tmp[i].c_str()));
            }
        }
    }

    return answer;
}

int main() {

    string s="{{20,111},{111}}";
    vector<int> result=solution(s);

    for(int i=0;i<result.size();i++) {
        printf("%d ",result[i]);
    }

    return 0;
}