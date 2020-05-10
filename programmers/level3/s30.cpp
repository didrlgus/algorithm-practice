// 야근 지수
#include <bits/stdc++.h>

using namespace std;

priority_queue<int,vector<int>,less<int>> pq;       // 최대힙
long long solution(int n, vector<int> works) {
    long long answer = 0;

    for(auto iter:works) pq.push(iter);
    
    while(n--) {
        int top=pq.top();
        pq.pop();
        top--;
        if(top<0) break;        // 0보다 작아지면 n이 남아있더라도 더이상 수행할 필요 x
        pq.push(top);
    }
    while(!pq.empty()) {
        int top=pq.top();
        pq.pop();
        answer+=pow(top,2);
    }
    return answer;
}

int main() {

    int n=4;
    vector<int> works={4,3,3};
    long long result=solution(n,works);
    printf("%lld\n",result);

    return 0;
}