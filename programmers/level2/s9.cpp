// 다리를 지나는 트럭
#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

struct p {
    int tw,time;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> q;   // 트럭 저장 큐
    deque<p> dq;     // 다리 내의 트럭 저장 큐

    vector<int> v;   // 다리를 건넌 트럭 저장 큐

    for(int i=0;i<truck_weights.size();i++) q.push(truck_weights[i]);

    // q    
    // dq   
    // sum  0
    // f    6
    // v    7 4 5 6
    // t    8
    int t=0;

    while(v.size()<truck_weights.size()) {
        for(int i=0;i<dq.size();i++) {
            dq[i].time+=1;
        }

        if(!dq.empty() && dq[0].time>bridge_length) {
            v.push_back(dq[0].tw);
            dq.pop_front();
        }

        if(!q.empty()) {
            int sum=0;
            for(int i=0;i<dq.size();i++) {
                sum+=dq[i].tw;
            }

            int f=q.front();
            if(sum+f<=weight) {
                dq.push_back({f,1});
                q.pop();
            }
        }
        answer++;
    }

    return answer;
}

int main() {

    vector<int> t={10,10,10,10,10,10,10,10,10,10};

    int result=solution(100,100,t);

    printf("%d\n",result);

    return 0;
}