// 라면공장
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;

    // 최대힙
    priority_queue<int,vector<int>,less<int>> pq;

    int idx=0;
    // k일 이전까지 밀가루 수를 유지시켜야 함
    for(int i=0;i<k;i++) {  // i는 일
        if(i==dates[idx] && idx<dates.size()) {
            pq.push(supplies[idx++]);
        }

        if(stock==0) {
            stock+=pq.top();
            pq.pop();
            answer++;
        }
        stock--;
    }

    return answer;
}

int main() {

    int stock=4;
    vector<int> dates={4,10,15};
    vector<int> supplies={20,5,10};
    int k=30;

    int result=solution(stock,dates,supplies,k);
    printf("%d\n",result);

    return 0;
}