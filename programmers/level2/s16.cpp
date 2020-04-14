// 더 맵게
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    // 최소힙
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<scoville.size();i++) pq.push(scoville[i]);
    
    // 1, 2, 3, 9, 10, 12
    while(pq.size()>=2) {
        int f=pq.top();
        pq.pop();
        int s=pq.top();
        pq.pop();

        int n=f+s*2;
        answer++;
        pq.push(n);

        if(pq.top()>=K) return answer;
    }

    return -1;
}

int main() {

    vector<int> scoville={1, 2, 3, 9, 10, 12};
    int K=7;

    int result=solution(scoville,K);
    printf("%d\n",result);

    return 0;
}