// 단속 카메라
#include<bits/stdc++.h> 

using namespace std;

bool cmp(vector<int> v1,vector<int> v2) {
    if(v1[1]==v2[1]) return v1[0]<v2[0];
    return v1[1]<v2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;

    // 나간 시간을 기준으로 오름차순 정렬
    sort(routes.begin(), routes.end(), cmp);

    // 카메라의 첫 위치 -> 첫 요소의 출차지점
    int cpos=routes[0][1];
    answer++;   // 카메라 설치

    for(int i=1;i<routes.size();i++) {
        if(cpos<routes[i][0]) {
            answer++;
            cpos=routes[i][1];      // 카메라 위치 설정
        }
    }

    return answer;
}

int main() {

    vector<vector<int>> routes={{-20,15},{-14,-5},{-18,-13},{-5,-3}};
    int result=solution(routes);
    printf("%d\n",result);

    return 0;
}