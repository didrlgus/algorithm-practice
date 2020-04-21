// 오픈채팅방
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

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

map<string,string> m;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<string> v1,v2;

    for(int i=0;i<record.size();i++) {
        vector<string> v3=split(record[i],' ');
        
        if(v3[0]=="Enter") {                    // enter uid1234 muzi
            v1.push_back(v3[1]);
            v2.push_back("님이 들어왔습니다.");
            m[v3[1]]=v3[2];
        } else if(v3[0]=="Leave") {             // leave uid1234
            v1.push_back(v3[1]);
            v2.push_back("님이 나갔습니다.");
        } else {
            m[v3[1]]=v3[2];                     // change uid4567 Ryan
        }
    }

    for(int i=0;i<v1.size();i++) {
        string s=m.find(v1[i])->second;
        answer.push_back(s+v2[i]);
    }

    return answer;
}

int main() {

    vector<string> record={"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234",
            "Enter uid1234 Prodo","Change uid4567 Ryan"};

    vector<string> result=solution(record);
    
    for(int i=0;i<result.size();i++) cout<<result[i]<<endl;

    return 0;
}