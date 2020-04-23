// 영어 끝말잇기
#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<string> s;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    s.insert(words[0]);
    int idx=0;

    for(int i=1;i<words.size();i++) {
        string s1=words[i-1], s2=words[i];

        // 중복 확인 && 글자 확인
        if(s.find(s2)==s.end() && s1.back()==s2.at(0)) s.insert(s2);
        else {
            idx=i;
            break;
        }
    }

    if(idx==0) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(idx%n+1);
        answer.push_back(idx/n+1);
    }

    return answer;
}

int main() {

    int n=2;
    vector<string> words={"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
    vector<int> result=solution(n,words);

    for(int i=0;i<result.size();i++) printf("%d ",result[i]);

    return 0;
}