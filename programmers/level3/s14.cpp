// 이중우선순위큐
#include<bits/stdc++.h>

using namespace std;

deque<int> dq;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(int i=0;i<operations.size();i++) {
        if(operations[i]=="D 1") {              // 최댓값을 삭제
            if(!dq.empty()) dq.pop_back();
        } else if(operations[i]=="D -1") {      // 최솟값을 삭제
            if(!dq.empty()) dq.pop_front();
        } else {
            int n=atoi(operations[i].substr(2).c_str());
            dq.push_back(n);
            sort(dq.begin(),dq.end());
        }
    }

    if(dq.empty()) {
        answer.push_back(0); 
        answer.push_back(0);
    } else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}

int main() {

    vector<string> operations={"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};
    vector<int> result=solution(operations);

    for(int i=0;i<result.size();i++) printf("%d ",result[i]);

    return 0;
}