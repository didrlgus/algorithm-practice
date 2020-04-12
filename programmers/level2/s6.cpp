// 스킬트리
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    vector<string> v;

    // skill        CBD
    // skill_trees  BACDE              
    for(int i=0;i<skill_trees.size();i++) {
        string s;
        for(int j=0;j<skill_trees[i].size();j++) {
            for(int k=0;k<skill.size();k++) {
                if(skill.at(k)==skill_trees[i].at(j)) {
                    s+=skill.at(k);
                    break;
                }
            }
        }
        v.push_back(s);
    }

    for(int i=0;i<v.size();i++) {
        bool flag=false;
        for(int j=0;j<v[i].size();j++) {
            if(skill.at(j)!=v[i].at(j)) {
                flag=true;
                break;
            }
        }
        if(!flag) answer++;
    }

    return answer;
}

int main() {

    string skill="CBD";
    vector<string> skill_trees={"BACDE", "CBADF", "AECB", "BDA"};

    int result=solution(skill,skill_trees);

    cout<<result<<endl;

    return 0;
}