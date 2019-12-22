// 모의고사
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int one[] = {1,2,3,4,5};
    int two[] = {2,1,2,3,2,4,2,5};
    int three[] = {3,3,1,1,2,2,4,4,5,5};
    
    int cnt1=0,cnt2=0,cnt3=0;
    
    for(int i=0;i<answers.size();i++) {
        if(answers[i]==one[i%5]) cnt1++;
        if(answers[i]==two[i%8]) cnt2++;
        if(answers[i]==three[i%10]) cnt3++;
    }
    
    if(cnt1>=cnt2 && cnt1>=cnt3) answer.push_back(1);
    if(cnt2>=cnt1 && cnt2>=cnt3) answer.push_back(2);
    if(cnt3>=cnt1 && cnt3>=cnt2) answer.push_back(3);
    
    return answer;
}

int main() {
    vector<int> answers = {1,3,2,4,2};
    
    vector<int> result = solution(answers);

    for(int i=0;i<result.size();i++) printf("%d ", result[i]);

    return 0;
}