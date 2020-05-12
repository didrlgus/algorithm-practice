// 기지국 설치
#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer=0;

    int location=1;
    int size=stations.size();
    int idx=0;

    while(location<=n) {
        if(idx<size && stations[idx]-w<=location) {         // 현재 위치가 기지국 범위에 포함되는 경우
            location=stations[idx]+w+1;                     // 현재 기지국의 +1 위치로 현재위치 수정
            idx++;                                          // 다음 기지국을 검사하기 위함
        } else if(idx>=size || stations[idx]-w>location) {  // 기지국을 모두 검사한 경우 || 현재위치가 기지국 범위에 포함되지 않는 경우
            location+=w*2+1;
            answer++;
        }
    }

    return answer;
}

int main() {
    int n=16;
    vector<int> stations={9};
    int w=2;

    int result=solution(n,stations,w);
    printf("%d\n",result);

    return 0;
}