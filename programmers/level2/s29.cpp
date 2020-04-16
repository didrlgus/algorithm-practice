// 최댓값과 최솟값
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

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

string solution(string s) {
    string answer = "";

    vector<string> v=split(s,' ');
    vector<int> v2;

    for(int i=0;i<v.size();i++) {
        v2.push_back(atoi(v[i].c_str()));
    }

    sort(v2.begin(),v2.end());

    answer+=to_string(v2[0]);
    answer+=" ";
    answer+=to_string(v2[v2.size()-1]);

    return answer;
}

int main() {

    string s="1 2 3 4";
    string result=solution(s);

    cout<<result<<endl;

    return 0;
}

