#include <vector>
#include <stack>
#include <cmath>
#include <cstdio>

using namespace std;

stack<int> s;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for(int i=progresses.size()-1;i>=0;i--) {
        int a = (int) ceil((float)(100-progresses[i])/speeds[i]);
        
        s.push(a);
    }
    
    while(!s.empty()) {
        int cnt=1;
        
        int top = s.top();
        s.pop();
        
        while(1) {
            if(s.size()<=0) break;
            
            if(top<s.top()) break;
            else {
                s.pop();
                cnt++;
            }
        }
        
        answer.push_back(cnt);
    }
        
    return answer;
}

int main() {

	vector<int> progresses;
	vector<int> speeds;

	progresses.push_back(93);
	progresses.push_back(30);
	progresses.push_back(55);

	speeds.push_back(1);
	speeds.push_back(30);
	speeds.push_back(5);

  vector<int> answer=solution(progresses, speeds);

  for(int i=0;i<answer.size();i++) printf("%d ", answer[i]);

	return 0;
}