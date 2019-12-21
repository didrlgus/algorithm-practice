// 완주하지 못한 선수
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    int size = participant.size();
    
    for(int i=0;i<size;i++) {
        if(!(i==size-1) && !(participant[i]==completion[i])) {
            answer=participant[i];
            break;
        }
        
        if(i==size-1) answer=participant[i];
    }
    
    return answer;
}

int main() {

    vector<string> participant, completion;

    participant.push_back("leo");
    participant.push_back("kiki");
    participant.push_back("eden");

    completion.push_back("eden");
    completion.push_back("kiki");

    string result = solution(participant, completion);

    for(int i=0;i<result.size();i++) {
        printf("%c",result[i]);
    }

    return 0;
}