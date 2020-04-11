// 프린터
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct p{
    int n;
    bool b;
};

queue<int> q1;
queue<p> q2; 

int solution(vector<int> priorities, int location) {
    int answer = 0;

    for(int i=0;i<priorities.size();i++) {
        if(i==location) {
            q2.push({priorities[i],true});
        } else {
            q2.push({priorities[i],false});
        }
    }

    // 내림차순 정렬
    sort(priorities.begin(),priorities.end(),greater<int>());

    for(int i=0;i<priorities.size();i++) q1.push({priorities[i]});

    while(!q1.empty()) {
        int f1=q1.front();
        int f2=q2.front().n;
        bool b=q2.front().b;

        //q1 -> 3    2    2    1
        //q2 -> 3(t) 2(f) 2(f) 1(f)
        if(f1>f2) {
            q2.pop();
            q2.push({f2,b});
        } else {
            q1.pop();
            q2.pop();
            answer++;

            if(b) break;
        }
    }

    return answer;
}

int main() {

    vector<int> p={2, 1, 3, 2};
    int location=2;

    int result=solution(p,location);
    printf("%d\n",result);

    return 0;
}