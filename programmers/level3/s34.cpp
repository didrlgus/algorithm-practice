// 징검다리 건너기
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;

    int s=1,e=200000000;

    // 친구 수를 기준으로 이분탐색
    while(s+1<e) {
        int mid=(s+e)/2;

        int cnt=0;
        for(int i=0;i<stones.size();i++) {
            if(stones[i]-mid<=0) cnt++;
            else cnt=0;

            if(cnt>=k) break; 
        }

        if(cnt>=k) e=mid;       // cnt==k와 같아지면 mid~e 까지 모두 다 건널 수 없는 상황임
        else s=mid;             // cnt<k(break가 한번도 걸리지 않은 경우) 일 경우, s~mid 까지 모두 다 건널 수 있는 상황임
    }

    answer=e;                   // e를 빼는 시점, 즉 s+1명의 친구가 징검다리를 건널 수 있는 최대 수가 됨

    return answer;
}

int main() {

    vector<int> stones={2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k=3;

    int result=solution(stones, k);
    printf("%d\n",result);

    return 0;
}