// [1차] 뉴스 클러스터링
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

vector<string> func(string str) {
    vector<string> v;

    // h   a    n  d  s  h  a  k  e
    // i  i+1
    for(int i=0;i<str.size()-1;i++) {
        char ch1=tolower(str[i]),ch2=tolower(str[i+1]);

        if(ch1>='a' && ch1<='z' && ch2>='a' && ch2<='z') {
            string s(1,ch1);
            s+=ch2;

            v.push_back(s);
        }
    }

    return v;
}

int solution(string str1, string str2) {
    int answer = 0;

    vector<string> v1,v2;
    v1=func(str1);
    v2=func(str2);

    if(v1.size()==0 && v2.size()==0) return 65536;

    map<string,int> map1,map2;
    set<string> set;

    for(int i=0;i<v1.size();i++) {
        if(map1.find(v1[i])==map1.end()) {    // 요소가 없을 경우
            map1.insert({v1[i],1});
            set.insert(v1[i]);
        } else {                            // 요소가 있을 경우
            map1.find(v1[i])->second++;
        }
    }

    for(int i=0;i<v2.size();i++) {
        if(map2.find(v2[i])==map2.end()) {    // 요소가 없을 경우
            map2.insert({v2[i],1});
            set.insert(v2[i]);
        } else {                            // 요소가 있을 경우
            map2.find(v2[i])->second++;
        }
    }

    int inter=0;
    for(auto iter : set) {
        if(map1.find(iter)!=map1.end() && map2.find(iter)!=map2.end()) {
            inter+=min(map1.find(iter)->second,map2.find(iter)->second);
        }
    }

    int uni=v1.size()+v2.size()-inter;

    answer=((double)inter/uni)*65536;

    return answer;
}

int main() {

    string str1="handshake";
    string str2="shake hands";

    int result=solution(str1,str2);
    printf("%d\n",result);

    return 0;
}