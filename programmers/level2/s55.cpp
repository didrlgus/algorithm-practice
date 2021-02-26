// 구명보트
#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end(),greater<>());
    int left=0,right=(int)people.size()-1;
    while(left<right) {
        if(people[left]+people[right]>limit) left++;
        else {
            left++;
            right--;
        }
        answer++;
    }
    if(left==right) answer++;
    return answer;
}
int main() {
    vector<int> people={70,50,80,50};
    int limit=100;
    printf("%d\n",solution(people,limit));
    return 0;
}