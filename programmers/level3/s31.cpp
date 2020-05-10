// 줄 서는 방법
#include<bits/stdc++.h>
using namespace std;

// 순열의 특징에 대한 문제, k번째 순열 구하기
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;
    long long factorial=1;

    for(int i=1;i<=n;i++) {
        v.push_back(i);
        factorial*=i;
    }

    long long remain=k-1;   // k는 1부터 시작이므로

    while(n>0) {
        factorial/=n--;
        long long val=remain/factorial;
        answer.push_back(v[val]);
        v.erase(v.begin()+val);
        remain%=factorial;
    }

    return answer;
}

int main() {

    int n=3; long long k=5;
    vector<int> result=solution(n,k);
    for(auto iter:result) printf("%d ",iter);

    return 0;
}